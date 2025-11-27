#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
using namespace std;

#define size 5
class Book
{
public:
    int id ;
    string title;
    string author;
    Book()
    {    id = 1 ;
        title = "rich dad poor dad";
        author = "robert";
    }
    Book(int id ,string title, string author)
    {   this-> id =id ;
        this->title = title;
        this->author = author;
    }

    void serialize(ofstream &fout){
        fout<<id<<"|"<<title<<"|"<<author<<endl ;
        
    }
    Book deserialize(string line ){
        Book b1;
        stringstream ss(line);
        string token ;
        getline(ss,token,'|');
        b1.id=(stoi(token));
        getline(ss,token,'|');
        b1.title=token;
        getline(ss,token,'|');
        b1.author = token ;
      
        return b1 ; 

    }

    ~Book() {}
};