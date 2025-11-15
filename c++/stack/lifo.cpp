#include<iostream>
#include<string>
using namespace std ; 
#define size 5
class Book{
    
    
    public:
        string title ;
        string auther ;
        Book(){
            this->title= "rich dad poor dad";
            this -> auther= "robert";
        }
        Book(string t, string a ){
            this->title =t ;
            this ->auther = a ;
        }

        ~Book(){}
};

class Shelf {
private:
    
public:
    int top;
    Book book[size];

    Shelf(){
        this->top = -1;
    }
    void push (Book thebook){
        top++;
        this -> book[top]=thebook ;
    }
};
int main()
{
    Shelf  motivationalShelf ;
    Book book1("You can win","Shiv khera");
    motivationalShelf.push(book1);
    Book book2("Ignited Minds","APJ Kalam");
    motivationalShelf.push(book2);
    Book book3("The Monk who sold his Ferrari", "Robhin Sharma");
    motivationalShelf.push(book3);

    Book book4("Mahabharat", "Vyas");
    motivationalShelf.push(book4);

    Book book5("Ramayan", "Walminki");
    motivationalShelf.push(book5);
    Book book6("M3", "Ram Pande");
    motivationalShelf.push(book6);
    cout<<motivationalShelf.book;
    return 0;
}
