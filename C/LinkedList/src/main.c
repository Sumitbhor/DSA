#include "../include/linkedlist.h"
#include "../include/uimanager.h"
#include "../include/filemanager.h"
int main(){
    int choice, item;

    struct LinkedList list;

    initList(&list);

    list = *deserialize("../data/data.txt");

    while (1)
    {
        showMenu();
        choice = acceptChoice();
        
        switch (choice)
        {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                insert(&list, item);
                break;
            case 2:
                printf("Enter item to search: ");
                scanf("%d", &item);
                search(&list, item);
                break;
            case 3:
                printf("Enter item to delete: ");
                scanf("%d", &item);
                delete(&list, item);
                break;
            case 4:
                display(&list);
                break;
            case 5:
                serialize("../data/data.txt", &list);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
            }
    }
    
}


//gcc -Iinclude src/linkedlist.c src/uimanager.c src/filemanager.c src/main.c -o build/main.exe
//gcc -Iinclude src/linkedlist.c src/uimanager.c src/filemanager.c src/main.c -o build/main.exe

