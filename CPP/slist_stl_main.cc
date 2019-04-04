#include "slist.h"

#include <algorithm>
#include <iostream>

/*
    check for compatibility with some STL-algorithms
        - std::count
*/

int main(int argc, char* argv[]) {
    SList<int> list;
    int elements[] = {1, 3, 2, 5, 6, 5, 5, 2};
    const unsigned int n = sizeof(elements) / sizeof(int);

    for (unsigned int i = 0; i < n; i++) {
        list.AddTail(elements[i]);
    }

    int value = 2;
    std::cout << std::count((int*)elements, elements + n, value) << std::endl;
    std::cout << std::count(list.begin(), list.end(), value) << std::endl;

    SList<float> list2;
    for (auto i = 0; i < n; ++i) {
        list2.AddTail(elements[i]);
    }
    std::cout << std::count(list2.begin(), list2.end(), value) << std::endl;
    return 0;
}