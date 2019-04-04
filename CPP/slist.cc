#include "slist.h"

/*
    don't want to include stdio.h just for NULL
    we will improve this with Modern-CPP
*/
SList::SNode::SNode(SList::DataType value) {
    data = value;
    next = 0;
}

SList::SList() {
    head = 0;
    tail = 0;
}

SList::~SList() {
    SNode * node, * temp;
    node = head;
    while (node != 0) {
        temp = node->next;
        delete node;
        node = temp;
    }
}

void SList::AddTail(SList::DataType data) {
    SNode * node = new SNode(data);
    if (head == 0) {
        /* Adding the first node */
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}


/*
    STL style supports
*/

SList::SListPointer SList::begin() {
    return {head};
}

SList::SListPointer SList::end() {
    return {0};
}

SList::SListPointer& SList::SListPointer::operator++() {
    current = current->next;
    return *this;
}

SList::SListPointer SList::SListPointer::operator++(int) {
    SList::SListPointer result(*this);
    ++(*this);
    return result;
}

SList::DataType SList::SListPointer::operator*() {
    return current->data;
}

bool SList::SListPointer::operator==(const SList::SListPointer& other) {
    return current == other.current;
}

bool SList::SListPointer::operator!=(const SList::SListPointer& other) {
    return current != other.current;
}