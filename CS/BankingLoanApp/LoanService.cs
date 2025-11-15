public class LoanService
{

private readonly List<Loan> _loans = new List<Loan>();
private readonly LoanProductService _productService;
private readonly AccountService _accountService;
private readonly INotificationService _notification;


public LoanService(LoanProductService prod, AccountService acctSvc, INotificationService notif)
{
    _productService = prod; 
    _accountService = acctSvc; 
    _notification = notif;
}

public Loan ApproveAndCreateLoan(LoanApplication app, Guid disburseAccountId)
{
    var prod = _productService.Get(app.LoanType);
    if (prod == null) throw new Exception("Product missing");
    var loan = new Loan
    {
        CustomerId = app.CustomerId,
        LoanType = app.LoanType,
        Principal = app.RequestedAmount,
        TenureMonths = app.RequestedTenureMonths,
        AnnualInterestRate = prod.InterestRateAnnual,
        DisbursalDate = DateTime.UtcNow,
        AccountId = disburseAccountId,
        OutstandingPrincipal = app.RequestedAmount
    };
    // generate schedule
    loan.Schedule = FinanceHelpers.GenerateAmortizationSchedule(loan.Principal, loan.AnnualInterestRate, loan.TenureMonths, loan.DisbursalDate);
    _loans.Add(loan);
    _notification.Notify(loan.CustomerId, $"Loan {loan.LoanId} approved and created.");
    return loan;
}

public void Disburse(Loan loan)
{
    _accountService.Credit(loan.AccountId, loan.Principal);
    loan.DisbursalDate = DateTime.UtcNow;
    foreach (var inst in loan.Schedule) // set due dates relative to disbursal
    {
    // already set by schedule generator
    }
    _notification.Notify(loan.CustomerId, $"Loan {loan.LoanId} disbursed to account {loan.AccountId}. Amount: {loan.Principal}");
}


public void MakeRepayment(Loan loan, decimal amount, DateTime paymentDate)
{
    if (amount <= 0) throw new ArgumentException("Payment amount must be > 0");
    // Apply payment to earliest unpaid installment
    foreach (var inst in loan.Schedule.Where(i => i.Status != InstallmentStatus.Paid).OrderBy(i => i.Sequence))
    {
        var remaining = inst.Amount - inst.PaidAmount;
        var pay = Math.Min(remaining, amount);
        inst.PaidAmount += pay;
        amount -= pay;
        if (inst.PaidAmount >= inst.Amount - 0.0001m) inst.Status = InstallmentStatus.Paid;
        // reduce outstanding principal by principal component proportionally
        // if paying early/partial, deduct principal proportionally to principal component share
        var principalShare = inst.PrincipalComponent;
        if (inst.Amount > 0)
        {
        var principalPaid = pay * (principalShare / inst.Amount);
        loan.OutstandingPrincipal -= principalPaid;
        }


        if (amount <= 0) break;
        }
        if (loan.OutstandingPrincipal < 0) loan.OutstandingPrincipal = 0;
        if (loan.IsClosed) _notification.Notify(loan.CustomerId, $"Loan {loan.LoanId} is fully repaid and closed.");
}


public IEnumerable<Loan> GetActiveLoans() => _loans.Where(l => !l.IsClosed);
public IEnumerable<Loan> GetOverdueLoans(DateTime now) => _loans.Where(l => l.Schedule.Any(i => i.DueDate < now && i.Status != InstallmentStatus.Paid));
public IEnumerable<Loan> GetByType(LoanType type) => _loans.Where(l => l.LoanType == type);





}