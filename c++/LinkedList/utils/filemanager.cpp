#include <string>
#include <fstream>
#include "../ds/linkedlist.h"
#ifndef UTILS_FILEMANAGER_CPP
#define UTILS_FILEMANAGER_CPP
using namespace std ;

class FileManager
{
    public:

        bool serialize(LinkedList list, string filename){

            bool status = false ;
        
            ofstream fout(filename);
            Node *ptrCurrentNode = list.ptrHead ;
            
            while (ptrCurrentNode != nullptr )
            {
                fout<<ptrCurrentNode->data<<endl ;
                status =true;
                ptrCurrentNode=ptrCurrentNode->next;
            }
            return status ;  
        }


        LinkedList deserialize(string filename){
            LinkedList list ;
            ifstream fin(filename);
            int value ;
            while (fin >> value){
                list.insert(value);
            }
            return list ;
        }
};
#endif // UTILS_FILEMANAGER_CPP