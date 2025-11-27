#include<stdio.h>
#include "linkedlist.h"
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

void serialize(const char* filename, struct LinkedList *list);
struct LinkedList* deserialize(const char* filename);
#endif