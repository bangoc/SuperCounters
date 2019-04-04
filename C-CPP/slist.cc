#include "slist.h"

#include <stdlib.h>

static SNode * SNodeCreate(DataType data) {
    SNode * node = (SNode*)malloc(sizeof(SNode));
    if (node) {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

SList * SListCreate(void) {
    SList * list = (SList*)malloc(sizeof(SList));
    if (list) {
        list->head = NULL;
        list->tail = NULL;
    }
    return list;
}

void SListDelete(SList * list) {
    SNode * node, * temp;
    node = list->head;
    while (node != NULL) {
        temp = node->next;
        free(node);
        node = temp;
    }
    free(list);
}

void SListAddTail(SList * list, DataType data) {
    SNode * node = SNodeCreate(data);
    if (list->head == NULL) {
        /* Adding the first node */
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

/*
    STL style supports
*/

SListPointer Begin(SList* list) {
    return {list->head};
}

SListPointer End(SList* list) {
    return {NULL};
}

SListPointer& operator++(SListPointer& pointer) {
    pointer.current = pointer.current->next;
    return pointer;
}

SListPointer operator++(SListPointer& pointer, int) {
    SListPointer result(pointer);
    ++pointer;
    return result;
}

DataType operator*(SListPointer& pointer) {
    return pointer.current->data;
}

bool operator==(SListPointer& pointer1, SListPointer& pointer2) {
    return pointer1.current == pointer2.current;
}

bool operator!=(SListPointer& pointer1, SListPointer& pointer2) {
    return pointer1.current != pointer2.current;
}