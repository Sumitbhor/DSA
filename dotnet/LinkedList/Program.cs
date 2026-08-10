using LinkedLists;
public class Program
{
    public static void Main(string [] args)
    {
        LinkedList list = new LinkedList();
        list.insert(25);
        list.insert(50);
        list.insert(98);
        list.insert(15);
        list.Display();
        list.insert(69);
        list.Display();
        list.update(25,89);
        list.Display();
        list.update(50,100);
        list.Display();
        list.Delete(100);
        list.Display();

    }
}