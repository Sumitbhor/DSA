public class LoanApplication
{
    public Guid ApplicationId { get; set; } = Guid.NewGuid();
    public Guid CustomerId { get; set; }
    public LoanType LoanType { get; set; }
    public decimal RequestedAmount { get; set; }
    public int RequestedTenureMonths { get; set; }
    public string Collateral { get; set; }
    public decimal ApplicantAnnualIncome { get; set; } // snapshot for DTI
    public ApplicationStatus Status { get; set; } = ApplicationStatus.Draft;
    public string OfficerNotes { get; set; }
    public Guid? ApprovedLoanId { get; set; }


    // Simple result of automated validations
    public List<string> ValidationMessages { get; set; } = new List<string>();
}