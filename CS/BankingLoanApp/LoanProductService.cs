public class LoanProductService
{
    private readonly List<LoanProduct> _products = new List<LoanProduct>();
    public void Add(LoanProduct p)
    {
        _products.Add(p);
        
    } 
    public LoanProduct Get(LoanType t)
    {
        return _products.FirstOrDefault(x => x.LoanType == t);

    } 
    public IEnumerable<LoanProduct> GetAll()
    {
      return _products;  
    } 
}