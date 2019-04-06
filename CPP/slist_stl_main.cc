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

    float f = 0.1f;
    float one = 0;
    for (int i = 0; i < 10; ++i) {
        one += f;
    }
    std::cout << "one = " << one << " " << std::endl;
    /*
        We will simplify this initialization in Modern-CPP
    */
    float elements2[] = {one, one, 2, 3, 5};
    SList<float> list2;
    for (auto i = 0; i < 5; ++i) {
        list2.AddTail(elements2[i]);
    }
    std::cout << std::count(list2.begin(), list2.end(), 1.0f) << std::endl;
    return 0;
}