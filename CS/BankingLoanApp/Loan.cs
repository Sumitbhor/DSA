public class Loan
{
    public Guid LoanId { get; set; } = Guid.NewGuid();
    public LoanType LoanType { get; set; }
    public Guid CustomerId { get; set; }
    public Guid AccountId { get; set; } // account to which disbursed
    public decimal Principal { get; set; }
    public int TenureMonths { get; set; }
    public decimal AnnualInterestRate { get; set; }
    public DateTime DisbursalDate { get; set; }
    public List<Installment> Schedule { get; set; } = new List<Installment>();
    public decimal OutstandingPrincipal { get; set; }
    public bool IsClosed => OutstandingPrincipal <= 0m || Schedule.All(i => i.Status == InstallmentStatus.Paid);
}