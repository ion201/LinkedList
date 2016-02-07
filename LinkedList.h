#pragma once

#include <stdlib.h>

typedef enum {false, true} bool;

typedef struct Node{
    struct Node* _prev;
    struct Node* _next;
    int _data;
} Node;

typedef struct LinkedList{
    struct Node* _tail;
    struct Node* _head;
    int size;
} LinkedList;

void ll_insert(LinkedList*, int, int);
void ll_append(LinkedList*, int);
int ll_getindex(LinkedList*, int);
LinkedList* ll_create();
void ll_clean(LinkedList*);
