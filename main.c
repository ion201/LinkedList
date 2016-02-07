#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

int main()
{
    LinkedList* mylist = ll_create();
    ll_append(mylist, 3);
    ll_append(mylist, 6);
    ll_append(mylist, 7);
    ll_insert(mylist, 4, 1);
    ll_append(mylist, 15);

    int val = ll_getindex(mylist, 4);
    printf("Value: %d at index %d\n", val, 4);

    ll_clean(mylist);

    return 0;
}
