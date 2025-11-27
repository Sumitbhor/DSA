class Node {
    
        int data ;
        Node next ;
        Node(int data ){
            this.data = data ;
            this.next = null ;
        }
}
class InnerLinkedList {
    Node head ;
    InnerLinkedList(){
        this.head =null ;
    }
    
    void insert(int item ){
        Node newNode = new Node(item);
        if(head ==null){
            head = newNode ;
            return ;
        }
        Node current = head ; 
        while (current.next != null) {
            current =current.next ;
        }
        current.next = newNode ;

    }
    void display(){
        if (head ==null) {
            System.out.println("list is empty  ");
        }
        Node current = head ;

        while (current != null) {
            System.out.print(current.data+" ->");
            current= current.next ;
        }
    }

    void search(int data){
        Node current= head;
        
        while (current!= null) {
            if (current.data == data) {
                System.out.println("number is found ");
                return ;
            }
            current=current.next ;
        }
    }

    

 }


public class LinkedList {
    public static void main (String [] args ){
        InnerLinkedList list = new InnerLinkedList();
        list.insert(5);
        list.insert(10);
        list.insert(15);
        list.search(5);
        list.search(10);
        list.search(15);
        list.display();
    }
}