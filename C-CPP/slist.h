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

/*
STL style supports
*/
struct SListPointer {
  SNode* current;
};
SListPointer Begin(SList* list);
SListPointer End(SList* list);
SListPointer& operator++(SListPointer& pointer);
SListPointer operator++(SListPointer& pointer, int);
DataType operator*(SListPointer& pointer);
bool operator==(SListPointer& pointer1, SListPointer& pointer2);
bool operator!=(SListPointer& pointer1, SListPointer& pointer2);

#endif /* SLIST_H */