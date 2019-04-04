#ifndef SLIST_H
#define SLIST_H

class SList {
 public:
  typedef int DataType;

  struct SNode {
      DataType data;
      SNode * next;
      SNode(DataType value);
  };

  /*
    Will have problem with copy, but we don't discuss it here
  */
  SList();
  ~SList();
  void AddTail(DataType data);

  /*
  STL style supports
  */
  struct SListPointer {
    SNode* current;

    SListPointer& operator++();
    SListPointer operator++(int);
    DataType operator*();
    bool operator==(const SListPointer& other);
    bool operator!=(const SListPointer& other);
  };

  SListPointer begin();
  SListPointer end();

 private:
  SNode * head;
  SNode * tail;
};

#endif /* SLIST_H */