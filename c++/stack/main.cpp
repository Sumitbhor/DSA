#include "filemanager.cpp"
int main()
{
    FileManager mgr ;
    int choice ;

    Shelf theShelf=mgr.loadFromFile() ;
    
    while (true)
    {
        cout<<" *****Menu****** "<<endl;
        cout <<"1.add book to shelf "<<endl ;
        cout <<"2.remove book from shelf " <<endl ;
        cout <<"3.display books"<<endl ;
        cout <<"4.save data to file"<<endl ; 
        cout <<"5.Exit"<<endl ;
        cout <<"enter your choice "<<endl ;

        cin >> choice ;
        cin.ignore();

        switch (choice)
        {
            case 1:{
                int id = theShelf.top+2;
                string title;
                string author;
                cout<<"enter title of the book"<<endl ;
                getline(cin, title);
                cout<< "enter name of author of the book "<< endl ;
                getline(cin, author); 
                Book book(id, title , author);
                theShelf.push(book);
                break;
            }
            case 2 : {
                int id ;
                theShelf.pop();
                break;
            }
            case 3 :
                theShelf.display();
                break;
            case 4 : 
                if (mgr.serialize(theShelf))
                {
                    cout <<"all are saved "<<endl ; 
                    break ; 
                }
                
            case 5 :
                return 0;
            default:
                cout<<"invalid choice "<< endl ; 
                break;
        } 
    }
}
//g++ book.cpp shelf.cpp main.cpp filemanager.cpp -o main.exe