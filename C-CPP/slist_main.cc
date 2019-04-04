#include "slist.h"

#include <iostream>

/*
  value type can be deduced from T,
  we will improve this in CPP
*/

template<typename T>
int MyCount(T begin, T end, DataType value) {
    int cc = 0;
    T pointer = begin;
    while (pointer != end) {
        if (*pointer == value) {
            ++cc;
        }
        ++pointer;
    }
    return cc;
}

int main(int argc, char* argv[])
{
    SList * list = SListCreate();
    int elements[] = {1, 3, 2, 5, 6, 5, 5, 2};
    const unsigned int n = sizeof(elements) / sizeof(int);

    /*
      problem: we have introduced a lot of new names in the global namespace
      solution: we will improve it with class encapsulation in CPP
    */
    for (unsigned int i = 0; i < n; i++) {
        SListAddTail(list, elements[i]);
    }

    int value = 2;
    std::cout << MyCount((int*)elements, elements + n, value) << std::endl;
    std::cout << MyCount(Begin(list), End(list), value) << std::endl;

    /*
      problem: we also forgot to release memory usage for list
      solution: we will improve this in CPP
    */
    return 0;
}