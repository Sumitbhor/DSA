namespace LinkedLists;

public class LinkedList
{
    Node? head;
    public void insert(int num)
    {
        Node? newNode = new Node(num);
        if (head == null)
        {
            head = newNode;
            return;
        }

        Node Current = head;

        while (Current.next != null)
        {
            Current = Current.next;
        }

        Current.next = newNode;
    }

    public void Display()
    {
        Node? Current = head;
        while (Current != null)
        {
            Console.Write($"{Current.data} -> ");
            Current = Current.next;
        }
        Console.WriteLine();
    }

    public void update(int data, int newdata)
    {
        Node? Current = head;

        while (Current != null)
        {
            if (Current.data == data)
            {
                Current.data = newdata;
                return;
            }

            Current = Current.next;
        }
    }

     public void Delete(int data)
{
    if (head == null)
    {
        return;
    }

    if (head.data == data)
    {
        head = head.next;
        return;
    }

    Node current = head;

    while (current.next != null)
    {
        if (current.next.data == data)
        {
            current.next = current.next.next;
            return;
        }

        current = current.next;
    }

    Console.WriteLine("Value not found.");
}
}