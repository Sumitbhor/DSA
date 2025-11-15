public class LoanProduct
{
    public LoanType LoanType { get; set; }
    public decimal InterestRateAnnual { get; set; } // e.g. 12.5 means 12.5%
    public decimal MaxAmount { get; set; }
    public int MinCreditScore { get; set; }
    public int MaxTenureMonths { get; set; }
    public decimal MinAmount { get; set; }
}