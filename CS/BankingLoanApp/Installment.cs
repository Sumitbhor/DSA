

public class Installment
{
    public int Sequence { get; set; }
    public DateTime DueDate { get; set; }
    public decimal Amount { get; set; } // EMI
    public decimal PrincipalComponent { get; set; }
    public decimal InterestComponent { get; set; }
    public InstallmentStatus Status { get; set; } = InstallmentStatus.Pending;
    public decimal PaidAmount { get; set; } = 0m;
}