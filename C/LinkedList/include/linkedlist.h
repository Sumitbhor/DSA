#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int item;
    struct Node *ptrnext;
};

struct LinkedList {
    struct Node *head;
};

void initList(struct LinkedList *list);
void insert(struct LinkedList *list, int item);
void search(struct LinkedList *list, int item);
void delete(struct LinkedList *list, int item);
void display(struct LinkedList *list);

#endif
