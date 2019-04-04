#include "slist.h"

#include <stdlib.h>

slist::snode * slist::snode_create(slist::datatype data)
{
    slist::snode * node = new slist::snode();
    if (node) {
        node->data = data;
        node->next = NULL;
    }

    return node;
}

slist::slist() {
    head = NULL;
    tail = NULL;
    count = 0;
}

void slist::slist_empty(slist * list)
{
    snode * node, * temp;
    node = list->head;
    while (node != NULL) {
        temp = node->next;
        free(node);
        node = temp;
    }
}

void slist::slist_delete(slist * list)
{
    if (list) {
        slist_empty(list);
        free(list);
    }
}

void slist::slist_add_tail(datatype data)
{
    snode * node = snode_create(data);
    if (head == NULL) {
        /* Adding the first node */
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
    count++;
}

void slist::slist_add_head(slist * list, datatype data)
{
    snode * node = snode_create(data);
    if (list->tail == NULL) {
        /* Adding the first node */
        list->head = node;
        list->tail = node;
    }
    else {
        node->next = list->head;
        list->head = node;
    }
    list->count++;
}

slist::datatype slist::slist_remove_head(slist * list)
{
    datatype data = 0;

    if (list->head) {
        snode *temp = list->head;
        if (list->head->next) {
            list->head = list->head->next;
        }
        else {
            /* List is now empty */
            list->head = NULL;
            list->tail = NULL;
        }
        data = temp->data;
        free(temp);
        list->count--;
        if (list->count == 1) {
            list->tail = list->head;
        }
    }

    return data;
}

slist::datatype slist::slist_remove_tail(slist * list)
{
    datatype data = 0;

    if (list->tail) {
        snode *current, *previous = NULL;
        current = list->head;
        while (current->next) {
            previous = current;
            current = current->next;
        }
        data = current->data;
        free(current);
        if (previous) {
            previous->next = NULL;
        }
        else {
            /* List is now empty */
            list->head = NULL;
            list->tail = NULL;
        }
        list->count--;
        if (list->count == 1) {
            list->head = list->tail;
        }
    }

    return data;
}

slist::datatype slist::slist_remove(slist *list, snode *node, snode *previous)
{
    datatype data;
    if (node == list->head) {
        data = slist_remove_head(list);
    }
    else {
        previous->next = node->next;
        data = node->data;
        list->count--;
        if (list->count == 1) {
            list->tail = list->head;
        }
        else if (node == list->tail) {
            list->tail = previous;
        }
        free(node);
    }
    return data;
}

void slist::slist_insert_before(slist * list, snode * node, snode * previous, datatype data)
{
    if (node == list->head) {
        slist_add_head(list, data);
    }
    else {
        snode * newnode = snode_create(data);
        newnode->next = node;
        previous->next = newnode;
        list->count++;
    }
}

slist::snode * slist::slist_insert_after(slist * list, slist::snode * node, slist::datatype data)
{
    snode * newnode;
    if (node == NULL) {
        slist_add_head(list, data);
        newnode = list->head;
    }
    else {
        newnode = snode_create(data);
        if (newnode) {
            newnode->next = node->next;
            node->next = newnode;
            if (node == list->tail) {
                list->tail = newnode;
            }
        }
        list->count++;
    }
    return newnode;
}

void slist::slist_for_each(const slist * list, slist_forfn fun)
{
    snode * node;
    for (node = list->head; node != NULL; node = node->next) {
        fun(node->data);
    }
}

unsigned int slist::slist_get_count(const slist * list)
{
    return list->count;
}


slist::snode_pointer slist::begin() {
    return {head};
}

slist::snode_pointer slist::end() {
    return {NULL};
}

slist::snode_pointer& slist::snode_pointer::operator++() {
    p = p->next;
    return *this;
}

slist::snode_pointer slist::snode_pointer::operator++(int) {
    snode_pointer result(*this);
    ++(*this);
    return result;
}

slist::datatype slist::snode_pointer::operator*() {
    return p->data;
}

bool slist::snode_pointer::operator==(const slist::snode_pointer& other) {
    return this->p == other.p;
}

bool slist::snode_pointer::operator!=(const snode_pointer& other) {
    return this->p != other.p;
}