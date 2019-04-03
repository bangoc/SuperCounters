#include "slist.h"

#include <iostream>

template<typename T>
int MyCount(T begin, T end, datatype value) {
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
    slist * list = slist_create();
    int elements[] = {1, 3, 2, 5, 6, 5, 5, 2};
    const unsigned int n = sizeof(elements) / sizeof(int);

    for (unsigned int i = 0; i < n; i++) {
        slist_add_tail(list, elements[i]);
    }

    int value = 2;
    std::cout << MyCount((int*)elements, elements + n, value) << std::endl;
    std::cout << MyCount(slist_begin(list), slist_end(list), value) << std::endl;
    return 0;
}