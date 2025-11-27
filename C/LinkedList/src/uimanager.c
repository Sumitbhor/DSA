#include "../include/uimanager.h"

void showMenu(){
    printf("\n1. Insert Item\n");
    printf("2. Search Item\n");
    printf("3. Delete Item\n");
    printf("4. Display List\n");
    printf("5. Save and Exit\n");
}

int acceptChoice(){
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}
    