public static class FinanceHelpers
{
    // monthlyRate is decimal fraction, e.g. 0.01 for 1% per month.
    public static decimal CalculateEMI(decimal principal, decimal monthlyRate, int months)
    {
        if (monthlyRate == 0) return principal / months;
        var r = (double)monthlyRate;
        var p = (double)principal;
        var n = months;
        var emi = (decimal)(p * r * Math.Pow(1 + r, n) / (Math.Pow(1 + r, n) - 1));
        return Decimal.Round(emi, 2);
    }


public static List<Installment> GenerateAmortizationSchedule(decimal principal, decimal annualRatePercent, int months, DateTime startDate)
{
        var monthlyRate = (annualRatePercent / 100m) / 12m;
        var emi = CalculateEMI(principal, monthlyRate, months);
        var schedule = new List<Installment>();
        var outstanding = principal;
        for (int m = 1; m <= months; m++)
        {
            var interest = Decimal.Round(outstanding * monthlyRate, 2);
            var principalComp = Decimal.Round(emi - interest, 2);
            if (m == months)
            {
            // adjust last payment to clear rounding
            principalComp = outstanding;
            emi = outstanding + interest;
            }
            outstanding -= principalComp;
            if (outstanding < 0) outstanding = 0;


            schedule.Add(new Installment
            {
                Sequence = m,
                DueDate = startDate.AddMonths(m),
                Amount = emi,
                PrincipalComponent = principalComp,
                InterestComponent = interest,
                Status = InstallmentStatus.Pending
            });

            }
            return schedule;
        }
}