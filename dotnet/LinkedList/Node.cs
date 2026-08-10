namespace LinkedLists;
class Node{
    public int data {get; set;}
    public Node? next {get; set;}

    public Node(int num)
    {
        this.data = num;
        this.next = null ;
    }
}