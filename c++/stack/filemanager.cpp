#include "shelf.cpp"
class FileManager
{
public:
    bool serialize(Shelf theshelf)
    {
        bool status = false;
        ofstream fout("shelf.txt");
        if (fout.is_open())
        {
            for (int i = 0; i <= theshelf.top; i++)
            {
                fout<<theshelf.book[i].id<<"|"<<theshelf.book[i].title<<"|"<< theshelf.book[i].author<<endl ;
                
                status = true;
            }
            fout.close();
            cout << "successfull save " << endl;
        }
        else
        {
            cout << "something wrong" << endl;
        }

        return status;  
    }

    Shelf loadFromFile()
    {
        Book book;
        Shelf theshelf;
        ifstream in("shelf.txt");
        string line;
        while (getline(in, line))
        {
            if (!line.empty())
                theshelf.push(book.deserialize(line));
        }
        return theshelf;
    }
};
