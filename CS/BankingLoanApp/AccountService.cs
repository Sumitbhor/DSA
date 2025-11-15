public class AccountService
{
    private readonly List<Account> _accounts = new List<Account>();

    public Account Create(Account a) { 
        _accounts.Add(a);
         return a; 
    }

    public Account Get(Guid accountId)
    {
        return  _accounts.FirstOrDefault(a => a.AccountId == accountId);

        
    }
    public IEnumerable<Account> GetByCustomer(Guid customerId)
    {

        return _accounts.Where(a => a.CustomerId == customerId);
        
    }     
    
    public void Credit(Guid accountId, decimal amount)
    {
        var a = Get(accountId);
        if (a == null)
         throw new Exception("Account not found"); 
        a.Balance += amount;
    }


    public void Debit(Guid accountId, decimal amount)
    {
      var a = Get(accountId); 
      if (a == null) throw new Exception("Account not found"); 
      if (a.Balance < amount) throw new Exception("Insufficient balance");
      a.Balance -= amount;
    }
    
}