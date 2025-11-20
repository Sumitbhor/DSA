#include<iostream>
using namespace std ;

class Node
{

    
public:
    int data ;
    Node *next;

    Node(int value){
        this->data= value ;
        this->next =nullptr ;
    }
    void serialize(){
        cout<<data<<endl ;
    }
    void deserialize(int value){
        data = value ;
    }
    
};

