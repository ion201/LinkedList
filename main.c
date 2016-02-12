#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

int main()
{
    LinkedList* mylist = ll_create();
    ll_append(mylist, 3);
    ll_append(mylist, 10);
    ll_append(mylist, 7);
    ll_insert(mylist, 4, 1);
    ll_append(mylist, 20);
    ll_insert(mylist, 3.2, 0);

    printf("Sorting...\n");
    ll_sort(mylist);

    for (int i = 0; i < mylist->size; i++){
        double val = ll_getindex(mylist, i);
        printf("Value: %f at index %d\n", val, i);
    }

    ll_clean(mylist);

    return 0;
}
