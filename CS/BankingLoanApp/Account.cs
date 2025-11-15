public class Account
{
    public Guid AccountId { get; set; } = Guid.NewGuid();
    public Guid CustomerId { get; set; }
    public AccountType AccountType { get; set; }
    public decimal Balance { get; set; }
    
}