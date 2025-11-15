public class LoanApplicationService
{

    private readonly List<LoanApplication> _applications = new List<LoanApplication>();
    private readonly ICreditCheckService _creditCheck;
    private readonly LoanProductService _productService;
    private readonly INotificationService _notification;

    public LoanApplicationService(ICreditCheckService creditCheck, LoanProductService prodSvc, INotificationService notification)
    {
        _creditCheck = creditCheck;
        _productService = prodSvc;
        _notification = notification;
    }

    public LoanApplication Create(LoanApplication a)
    {
        _applications.Add(a);
        return a;
    }


    public LoanApplication Get(Guid id)
    {
      return _applications.FirstOrDefault(x => x.ApplicationId == id);  
    } 


    public LoanApplication Submit(Guid applicationId)
    {
        var app = Get(applicationId);
        if (app == null) throw new Exception("Application not found");
        app.Status = ApplicationStatus.Submitted;
        _notification.Notify(app.CustomerId, $"Loan application {app.ApplicationId} submitted.");
        return app;
    }


public LoanApplication RunAutomatedChecks(Guid applicationId)
{
    var app = Get(applicationId); 
    if (app == null) throw new Exception("Application not found");
    app.ValidationMessages.Clear();

    var prod = _productService.Get(app.LoanType);
    if (prod == null) 
        app.ValidationMessages.Add("Loan product configuration missing");
    else
    {
        if (app.RequestedAmount < prod.MinAmount || app.RequestedAmount > prod.MaxAmount)
        app.ValidationMessages.Add($"Requested amount outside allowed range [{prod.MinAmount} - {prod.MaxAmount}]");
        if (app.RequestedTenureMonths > prod.MaxTenureMonths)
        app.ValidationMessages.Add($"Requested tenure exceeds max {prod.MaxTenureMonths} months");
        var creditScore = _creditCheck.GetCreditScore(app.CustomerId);
        if (creditScore < prod.MinCreditScore) app.ValidationMessages.Add($"Credit score {creditScore} < required {prod.MinCreditScore}");

        // Debt-to-Income (DTI) basic check: monthly EMI should not exceed 40% of monthly income
        if (app.ApplicantAnnualIncome <= 0)
        app.ValidationMessages.Add("Applicant income not provided for DTI check");
        else
        {
            var monthlyIncome = app.ApplicantAnnualIncome / 12m;
            var monthlyRate = (prod.InterestRateAnnual / 100m) / 12m;
            var emi = FinanceHelpers.CalculateEMI(app.RequestedAmount, monthlyRate, app.RequestedTenureMonths);
            if (emi > monthlyIncome * 0.4m)
                app.ValidationMessages.Add($"DTI failed: EMI {emi:F2} > 40% of monthly income {monthlyIncome:F2}");
            }
        }


        if (app.ValidationMessages.Any())
            app.Status = ApplicationStatus.UnderReview; // needs manual attention
        else 
            app.Status = ApplicationStatus.UnderReview; // still under review but cleared automated checks


        _notification.Notify(app.CustomerId, $"Automated validation completed for application {app.ApplicationId}. Results: {(app.ValidationMessages.Any() ? string.Join(';', app.ValidationMessages) : "Passed")}");
        return app;
        }


}
