#include "node.h"
#ifndef DS_LINKEDLIST_H
#define DS_LINKEDLIST_H
class LinkedList
{
    public:
        Node *ptrHead ;
        
        LinkedList();
        void insert(int item);
        void remove(int item );
        void search(int item );
        void display();
};
#endif // DS_LINKEDLIST_H