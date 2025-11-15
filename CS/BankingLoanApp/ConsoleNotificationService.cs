public class ConsoleNotificationService : INotificationService
{
    private readonly Func<Guid, string> _who;
    public ConsoleNotificationService(Func<Guid, string> who = null)
     {
         _who = who ?? (id => id.ToString());
     }
    public void Notify(Guid customerId, string message)
    {
        Console.WriteLine($"[Notification] To={_who(customerId)}: {message}");
    }
}