#include <stdio.h>

#include "LinkedList.h"

void ll_insert(LinkedList* l, int item, int index){
    if (index > l->size){
        printf("Cannot add item %d at index %d", item, index);
        printf("Requested index exceeds list size");
        return;
    }

    int i;
    bool reverse;
    Node* curNode;
    if (index <= l->size / 2){
        reverse = false;
        i = 0;
        curNode = l->_tail;
    } else{
        reverse = true;
        i = l->size - 1;
        curNode = l->_head;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->_data = item;
    if (curNode != NULL){
        if (index != l->size){
            while (i != index){
                if (reverse){
                    curNode = curNode->_prev;
                } else{
                    curNode = curNode->_next;
                }
                i ++;
            }
            //Insert new value before curNode
            newNode->_prev = curNode->_prev;
            newNode->_next = curNode;
            curNode->_prev = newNode;
            curNode->_prev->_next = newNode;
        } else{
            newNode->_prev = curNode;
            newNode->_next = NULL;
            curNode->_next = newNode;
            l->_head = newNode;
        }
    } else{
        newNode->_prev = NULL;
        newNode->_next = NULL;
        l->_head = newNode;
        l->_tail = newNode;
    }
    l->size ++;
    printf("Elment %d inserted at %d\n", item, index);
}

void ll_append(LinkedList* l, int a){
    ll_insert(l, a, l->size);
}

int ll_getindex(LinkedList* l, int i){
    if (i < 0 || i > l->size)
        return NULL;

    Node* n = l->_head;
    while (l->size - i > 1){
        n = n->_prev;
        i ++;
    }
    return n->_data;
}

LinkedList* ll_create(){
    LinkedList* newlist;
    newlist = (LinkedList*) malloc(sizeof(LinkedList));
    newlist->_head = NULL;
    newlist->_tail = NULL;
    newlist->size = 0;

    return newlist;
}

void ll_clean(LinkedList* l){
    Node* n;
    Node* nbuf;
    n = l->_head;
    while (n != NULL){
        nbuf = n->_prev;
        free(n);
        n = nbuf;
    }
    free(l);
}
