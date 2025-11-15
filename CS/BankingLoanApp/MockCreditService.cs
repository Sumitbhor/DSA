public class MockCreditCheckService : ICreditCheckService
{
    private readonly IDictionary<Guid, int> _scores;
    private readonly int _default;
    public MockCreditCheckService(IDictionary<Guid, int> scores = null, int defaultScore = 650)
    {
        _scores = scores ?? new Dictionary<Guid, int>();
        _default = defaultScore;
    }
    public int GetCreditScore(Guid customerId)
    {
        return _scores.ContainsKey(customerId) ? _scores[customerId] : _default;
    }
}


