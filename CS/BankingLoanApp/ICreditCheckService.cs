public interface ICreditCheckService
{
// Returns credit score for given customer id. Implementations may mock or call external systems.
int GetCreditScore(Guid customerId);
}