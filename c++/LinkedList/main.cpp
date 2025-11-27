#include <iostream>
#include "utils/filemanager.cpp"
#include "utils/uimanager.cpp"
#include "ds/linkedlist.h"

int main (){
    
    FileManager mgrFileIO ;

    LinkedList list ;

    UIManager mgrUI ;
    list = mgrFileIO.deserialize("data.txt");

    int choice ;
    while (true)
    {
        mgrUI.showMenu();
        choice = mgrUI.getChoice(choice);
        switch (choice) {
            case 1 :
                {
                    int item ;
                    cout<<"enter value to insert "<< endl ;
                    cin>> item ;
                    list.insert(item);
                    break ;
            } 

            case 2 :
                {
                    int item ;
                    cout<<"enter value to search "<< endl ;
                    cin>> item ;
                    list.search(item);
                    break ;
            }   

            case 3 :
                {
                    list.display();
                    break ;
            }

            case 4 :
                {
                    int item ;
                    cout<<"enter value to remove "<< endl ;
                    cin>> item ;
                    list.remove(item);
                    break ;
            }

            case 5 :
                {
                    mgrFileIO.serialize(list, "data.txt");
                return 0    ;
            }



        }
    
    }
}

//g++ ds\linkedlist.cpp ds\node.cpp utils\filemanager.cpp utils\uimanager.cpp main.cpp -o main.exe

// main.exe
