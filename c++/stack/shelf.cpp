#include "book.cpp"
class Shelf
{

public:
    int top;
    Book book[size];

    Shelf()
    {
        this->top = -1;
    }
    void push(Book thebook)
    {
        if (top < size)
        {
            top++;
            this->book[top] = thebook;
        }
    }
    Book pop()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
        }
        Book b1 = book[top];
        top--;
        return b1;
    }
    void display(){
        int choice ;
        cout<<"*****Menu******"<<endl;
        cout<<"1.display by id "<<endl ;

        cout<<"2. display all books "<<endl;
        cout<<"enter your choice "<< endl ;
        cin>>choice ;
        switch (choice)
        {
        case 1:
        {
            int id ;   
            cout<<"enter id "<<endl;
            cin>> id ;
            cout <<book[id-1].title <<"by "<<book[id-1].author<<endl;
            break;
        }
        case 2: {
             for (int i = top; i >-1 ; i--)
            {
                
                cout << "id "<<book[i].id<<" title : "<<book[i].title << " -> auther : " << book[i].author << endl;
            }
            break;
        }
        default:
            cout<<"invalid choice "<<endl ;
            break;
        }
    }
};