#include <stdio.h>

#include "LinkedList.h"

void ll_insert(LinkedList* l, double item, int index){
    if (index > l->size){
        printf("Cannot add item %f at index %d", item, index);
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
}

void ll_append(LinkedList* l, double a){
    ll_insert(l, a, l->size);
}

Node* ll_getindexnode(LinkedList* l, int i){
    Node* n = l->_head;
    while (l->size - i > 1){
        n = n->_prev;
        i ++;
    }
    return n;
}

void ll_swap_index(LinkedList* l, int index_a, int index_b){
    Node* n1 = ll_getindexnode(l, index_a);
    Node* n2 = ll_getindexnode(l, index_b);
    double buff = n1->_data;
    n1->_data = n2->_data;
    n2->_data = buff;
}

double ll_getindex(LinkedList* l, int i){
    if (i < 0 || i >= l->size)
        return ll_INDEX_ERROR;
    return ll_getindexnode(l, i)->_data;
}

int _ll_deafult_key(double a, double b){
    if (a <= b){
        return 0;
    } else{
        return 1;
    }
}

void ll_sort_key(LinkedList* l, int (*key)(double, double)){
    // Key(a, b) should return:
    // 0    - a sorted below b
    // != 0 - b sorted below a

    int i, j, min;
    for (i=0; i < l->size; i++){
        min = i;
        for (j=i+1; j < l->size; j++){
            if (key(ll_getindex(l, min), ll_getindex(l, j)) != 0){
                min = j;
            }
        }
        ll_swap_index(l, i, min);
    }
}

void ll_sort(LinkedList* l){
    ll_sort_key(l, &_ll_deafult_key);
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
