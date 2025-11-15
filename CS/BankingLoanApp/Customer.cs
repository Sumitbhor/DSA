
public class Customer{

    public Guid CustomerId { get; set; } = Guid.NewGuid();

    //Properties

    public string FullName { get; set; }
    public DateTime DOB { get; set; }
    public string PAN_SSN { get; set; }
    public string Email { get; set; }
    public string Phone { get; set; }
    public string Address { get; set; }
    public int CreditScore { get; set; }
    public decimal AnnualIncome { get; set; } // used for DTI check


    //Member function
    public override string ToString() {
        return $"{FullName} ({CustomerId})";
    }

}

