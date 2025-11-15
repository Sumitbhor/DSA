public class SimpleLoanOfficer : ILoanOfficer
{
    private readonly string _name;
    public SimpleLoanOfficer(string name = "Officer") { _name = name; }
    public (bool Approved, string Notes) Review(LoanApplication application)
    {
        // Very simple interactive-like decision: approve if automated validations passed; otherwise reject.
        bool approved = !application.ValidationMessages.Any();
        string notes = approved ? $"Approved by {_name}" : $"Rejected by {_name}: {string.Join(';', application.ValidationMessages)}";
        return (approved, notes);
    }
}