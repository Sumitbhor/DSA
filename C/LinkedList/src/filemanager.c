#include "../include/filemanager.h"
void serialize(const char* filename, struct LinkedList *list){
    FILE *file = fopen(filename, "w");
    struct Node *ptrcurrent = list->head ;
    while (ptrcurrent != NULL)
    {
        fprintf(file , "%d -> ", ptrcurrent->item);
        ptrcurrent = ptrcurrent->ptrnext ;
    }
    fclose(file);
}

struct LinkedList* deserialize(const char* filename){
    FILE *file =fopen(filename , "r");
    struct LinkedList *list = malloc(sizeof(struct LinkedList));
    initList(list);
    int item;
    while (fscanf(file , "%d -> " , &item) != EOF)
    {
        insert(list, item);
    }
    fclose(file);
    return list;
}