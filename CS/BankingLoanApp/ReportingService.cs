public class ReportingService
{
    private readonly LoanService _loanService;
    public ReportingService(LoanService loanService) { _loanService = loanService; }
    public void PrintActiveLoans() {
    var loans = _loanService.GetActiveLoans();
    Console.WriteLine("Active Loans:");
    foreach (var l in loans) Console.WriteLine($"Loan {l.LoanId}, Customer {l.CustomerId}, Outstanding {l.OutstandingPrincipal:F2}");
    }
    public void PrintOverdueLoans() {
    var loans = _loanService.GetOverdueLoans(DateTime.UtcNow);
    Console.WriteLine("Overdue Loans:");
    foreach (var l in loans) Console.WriteLine($"Loan {l.LoanId}, Customer {l.CustomerId}, Overdue Count {l.Schedule.Count(i => i.DueDate < DateTime.UtcNow && i.Status != InstallmentStatus.Paid)}");
    }
    public void PrintPortfolioByType() {
    Console.WriteLine("Portfolio by Loan Type:");
    foreach (LoanType t in Enum.GetValues(typeof(LoanType)))
    {
    var count = _loanService.GetByType(t).Count();
    Console.WriteLine($"{t}: {count}");
    }
}
}