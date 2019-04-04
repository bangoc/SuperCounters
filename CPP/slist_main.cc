#include "slist.h"

#include <iostream>

template<typename T>
int MyCount(T begin, T end, int value) {
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
    slist list;
    int elements[] = {1, 3, 2, 5, 6, 5, 5, 2};
    const unsigned int n = sizeof(elements) / sizeof(int);

    for (unsigned int i = 0; i < n; i++) {
        list.slist_add_tail(elements[i]);
    }

    int value = 2;
    std::cout << MyCount((int*)elements, elements + n, value) << std::endl;
    std::cout << MyCount(list.begin(), list.end(), value) << std::endl;
    return 0;
}