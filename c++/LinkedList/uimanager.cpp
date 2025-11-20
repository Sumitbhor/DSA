#include "LinkedList.cpp"

class uimanager
{
public:

    void menu(){
        cout<<"***** Menu *****"<<endl ;
        cout <<"1. insert new node "<<endl ;
        cout <<"2.search node "<<endl ;
        cout <<"3.display all nodes  "<<endl ;
        cout <<"4. remove node "<<endl ;
        cout <<"5. Exit   "<<endl ;
    }
    int getchoice (int choice ){
        cout <<"enter your choice "<< endl ; 
        cin >> choice;
        return choice;
    }
    LinkedList insertNode(LinkedList list){
        int value ;
        cout<<"enter value to insert "<< endl ;
        cin >> value ;
        list.insert(value);
        return list ;
    }
    void searchNode(LinkedList list){
        int value ;
        cout<<"enter value to search "<< endl ;
        cin >> value ;
        list.search(value);
    }

    LinkedList removeNode(LinkedList list){
        int value ;
        cout<<"enter value to remove "<< endl ;
        cin >> value ;
        list.remove(value);
        return list ;
    }
    void displayNodes(LinkedList list){
        list.display();
    }
    void exitProgram(){
        cout<<"exiting program ......"<< endl ;
        return ;
    }
};

