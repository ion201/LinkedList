#pragma once

#include <stdlib.h>

#define ll_INDEX_ERROR 10212.21561212

typedef enum {false, true} bool;

typedef struct Node{
    struct Node* _prev;
    struct Node* _next;
    double _data;
} Node;

typedef struct LinkedList{
    struct Node* _tail;
    struct Node* _head;
    int size;
} LinkedList;

void ll_insert(LinkedList*, double, int);
void ll_append(LinkedList*, double);
Node* ll_getindexnode(LinkedList*, int);
double ll_getindex(LinkedList*, int);
void ll_swap_index(LinkedList*, int, int);
void ll_sort(LinkedList*);
void ll_sort_key(LinkedList*, int(*)(double, double));
LinkedList* ll_create();
void ll_clean(LinkedList*);
