#include "slist.h"

#include <stdio.h>

/*
  problem: Different implementation for each container type
  solution: we will improve this in C-CPP
*/

int MyCount(int* begin, int* end, DataType value) {
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

int MyCountSlist(SList* list, DataType value) {
    int cc = 0;
    SNode* node = list->head;
    for (; node != NULL; node = node->next) {
        if (node->data == value) {
            ++cc;
        }
    }
    return cc;
}

int main(int argc, char* argv[])
{
    SList * list = SListCreate();
    int elements[] = {1, 3, 2, 5, 6, 5, 5, 2};
    const unsigned int n = sizeof(elements) / sizeof(int);

    for (unsigned int i = 0; i < n; i++) {
        SListAddTail(list, elements[i]);
    }

    int value = 2;
    printf("%d\n", MyCount((int*)elements, elements + n, value));
    printf("%d\n", MyCountSlist(list, value));

    /*
      forgot to free memory of list
    */
    return 0;
}