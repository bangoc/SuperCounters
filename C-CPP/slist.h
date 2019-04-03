#ifndef SLIST_H
#define SLIST_H

typedef int datatype;

struct snode {
    datatype data;
    struct snode * next;
};
typedef struct snode snode;

struct slist {
    snode * head;
    snode * tail;
    unsigned int count;
};
typedef struct slist slist;

typedef void (*slist_forfn)(datatype);

slist * slist_create(void);
void slist_empty(slist * list);
void slist_delete(slist * list);
void slist_add_tail(slist * list, datatype data);
void slist_add_head(slist * list, datatype data);
datatype slist_remove_head(slist * list);
datatype slist_remove_tail(slist * list);
datatype slist_remove(slist *list, snode *node, snode *previous);
void slist_insert_before(slist * list, snode * node, snode * previous, datatype data);
snode * slist_insert_after(slist * list, snode * node, datatype data);
void slist_for_each(const slist * list, slist_forfn fun);
unsigned int slist_get_count(const slist * list);

/*
STL style supports
*/
struct snode_pointer {
  snode* p;
};
snode_pointer slist_begin(slist* list);
snode_pointer slist_end(slist* list);
snode_pointer& operator++(snode_pointer& obj);
snode_pointer operator++(snode_pointer& obj, int);
datatype operator*(snode_pointer& obj);
bool operator==(snode_pointer& obj1, snode_pointer& obj2);
bool operator!=(snode_pointer& obj1, snode_pointer& obj2);

#endif /* SLIST_H */