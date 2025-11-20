#include "Node.cpp"
class LinkedList
{
private:
    Node *head ;
public:
    LinkedList(){
        this -> head =nullptr ;
    }
    void insert(int item){
        Node * newNode= new Node(item) ;
        if (head == nullptr){
            head = newNode ;
            return ;
        }
        Node * currentNode = head ;
        while (currentNode->next != nullptr )
        {
            currentNode= currentNode->next ;
        }
        
        currentNode->next = newNode ;
        
    }

    void search(int item ){
        
        Node * currentNode = head ; 
        int i = 0 ;
        while (currentNode != nullptr)
        {   
            
            if (currentNode->data == item){
                cout<<item<<" found at position "<< i << endl ;
                return ;
            }
            
            currentNode = currentNode->next ;
            i++;
        }
    }

    void display(){
        Node * currentNode = head ;
        if (currentNode == nullptr)
        {
            cout<<"list is empty "<< endl ;
            return ;
        }
        cout<<"start ";
        while (currentNode  != nullptr){
            cout<<currentNode->data<<" ->";
            currentNode = currentNode->next ;
        }
        cout<<"end"<<endl ;
    }
    
        void remove(int item ){
            if (head->data == item){
        
                head = head->next;
                return ;
            }

            Node *previousNode = nullptr ;
            Node *currentNode = head ; 
            //case 2 : if is between staring and ending 
            while (currentNode->next!= nullptr)
            {
                previousNode=currentNode;
                currentNode = currentNode ->next ;
                if (currentNode->data == item ){

                    previousNode->next = currentNode ->next ;
                    return ;
                }               
            }

            cout << "number not found "<<endl ;
        }
};


