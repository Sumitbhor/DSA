
public class CustomerService
{
    private readonly List<Customer> _customers = new List<Customer>();

    public Customer Create(Customer c) 
    {
         _customers.Add(c); 
         return c; 
    }

    public Customer Update(Customer c)
    {
        var idx = _customers.FindIndex(x => x.CustomerId == c.CustomerId);
        if (idx >= 0) _customers[idx] = c;
        return c;
    }

    public Customer Get(Guid customerId)
    {
       return _customers.FirstOrDefault(x => x.CustomerId == customerId);

    } 

    public IEnumerable<Customer> GetAll()
    {
      return _customers;
    } 
}