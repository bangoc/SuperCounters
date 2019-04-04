#ifndef SLIST_H
#define SLIST_H

typedef int DataType;

struct SNode {
    DataType data;
    struct SNode * next;
};
typedef struct SNode SNode;

struct SList {
    SNode * head;
    SNode * tail;
};
typedef struct SList SList;

SList * SListCreate(void);
void SListDelete(SList * list);
void SListAddTail(SList * list, DataType data);

#endif /* SLIST_H */