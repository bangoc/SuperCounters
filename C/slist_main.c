#include "slist.h"

#include <stdio.h>

/*
  problem: Different implementation for each container type
  solution: we will improve this in C-CPP
*/

int MyCount(int* begin, int* end, datatype value) {
    int cc = 0;
    int* pointer = begin;
    while (pointer != end) {
        if (*pointer == value) {
            ++cc;
        }
        ++pointer;
    }
    return cc;
}

int MyCountSlist(slist* list, datatype value) {
    int cc = 0;
    snode* node = list->head;
    for (; node != NULL; node = node->next) {
        if (node->data == value) {
            ++cc;
        }
    }
    return cc;
}

int main(int argc, char* argv[])
{
    slist * list = slist_create();
    int elements[] = {1, 3, 2, 5, 6, 5, 5, 2};
    const unsigned int n = sizeof(elements) / sizeof(int);

    for (unsigned int i = 0; i < n; i++) {
        slist_add_tail(list, elements[i]);
    }

    int value = 2;
    printf("%d\n", MyCount((int*)elements, elements + n, value));
    printf("%d\n", MyCountSlist(list, value));
    return 0;
}