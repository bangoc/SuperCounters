#ifndef SLIST_H
#define SLIST_H

#include <iostream>
#include <initializer_list>
#include <iterator>

template<typename DataType>
class SList {
 public:

  struct SNode {
      DataType data;
      SNode * next;
      SNode(DataType value) {
        data = value;
        next = nullptr;
      }
  };

  /*
    Will have problem with copy, but we don't discuss it here
  */
  SList() : SList ({}) {
  }

  SList(std::initializer_list<DataType> values) {
    head = tail = nullptr;
    for (DataType data: values) {
      AddTail(data);
    }
  }

  ~SList() {
    SNode * node, * temp;
    node = head;
    while (node != nullptr) {
        temp = node->next;
        delete node;
        node = temp;
    }
  }

  void AddTail(DataType data) {
    SNode * node = new SNode(data);
    if (head == nullptr) {
        /* Adding the first node */
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
  }

  /*
  STL supports
  */
  struct SListPointer
      : public std::iterator<std::forward_iterator_tag,
                             DataType,
                             long,
                             DataType*,
                             DataType&> {
    SListPointer(SNode* pointer) {
      current = pointer;
    }

    SNode* current;

    SListPointer& operator++() {
      current = current->next;
      return *this;
    }

    SListPointer operator++(int) {
      SList::SListPointer result(*this);
      ++(*this);
      return result;
    }

    DataType operator*() {
      return current->data;
    }

    bool operator==(const SListPointer& other) {
      return current == other.current;
    }

    bool operator!=(const SListPointer& other) {
      return current != other.current;
    }
  };

  SListPointer begin() {
    return {head};
  }

  SListPointer end() {
    return {nullptr};
  }

 private:
  SNode * head;
  SNode * tail;
};

#endif /* SLIST_H */