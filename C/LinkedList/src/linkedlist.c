#include "../include/linkedlist.h"

void initList(struct LinkedList *list ){
    list->head = NULL ;
}

void insert(struct LinkedList *list, int item)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->item = item;
    newNode->ptrnext = NULL;        
    if (list->head == NULL)
    {
        list->head = newNode ;
    }
    else 
    {
        struct Node *ptrcurrent = list->head ;
        while (ptrcurrent->ptrnext != NULL)
        {
            ptrcurrent = ptrcurrent->ptrnext ;
        }
        ptrcurrent->ptrnext = newNode ;
        
    }
}
void search(struct LinkedList *list,int item){
    struct Node *ptrcurrent = list->head ;
    while (ptrcurrent!=NULL)
    {
        if (ptrcurrent->item == item)
        {
            printf("Item found: %d\n", item);
            return;
        }
        ptrcurrent= ptrcurrent->ptrnext;
    }
    printf("Item not found: %d\n", item);
}

void delete(struct LinkedList *list,int item){
    struct Node *ptrcurrent = list->head ;
    struct Node *ptrprevious = NULL ;
    while (ptrcurrent!=NULL)
    {
        if (ptrcurrent->item == item)
        {
            if (ptrprevious == NULL)
            {
                list->head = ptrcurrent->ptrnext ;
            }
            else {
                ptrprevious->ptrnext = ptrcurrent->ptrnext ;
            }
            free(ptrcurrent);
            printf("Item deleted: %d\n", item);
            return;
        }
        ptrprevious = ptrcurrent ;
        ptrcurrent= ptrcurrent->ptrnext;
    }
    printf("Item not found for deletion: %d\n", item);
}

void display(struct LinkedList *list)
{
    struct Node *ptrcurrent = list->head ;
    while (ptrcurrent != NULL)
    {
        printf("%d -> ", ptrcurrent->item);
        ptrcurrent = ptrcurrent->ptrnext;
    }
    printf("NULL\n");

}


    