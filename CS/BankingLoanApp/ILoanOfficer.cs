public interface ILoanOfficer
{
// Decision: approve or reject. Officer can add notes.
(bool Approved, string Notes) Review(LoanApplication application);
}