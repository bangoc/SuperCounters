#include "slist.h"

#include <iostream>

/*
   compare == is unsafe for floating value,
   how can we limit this count only for integral types?
   we will improve it in Modern-CPP
 */
template<typename T>
int MyCount(T begin, T end,
            typename std::iterator_traits<T>::value_type value) {
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

int main(int argc, char* argv[]) {
    SList<int> list;
    int elements[] = {1, 3, 2, 5, 6, 5, 5, 2};
    const unsigned int n = sizeof(elements) / sizeof(int);

    for (unsigned int i = 0; i < n; i++) {
        list.AddTail(elements[i]);
    }

    int value = 2;
    std::cout << MyCount((int*)elements, elements + n, value) << std::endl;
    std::cout << MyCount(list.begin(), list.end(), value) << std::endl;

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

    // Unsafe floating point comparison
    std::cout << MyCount(list2.begin(), list2.end(), 1.0f) << std::endl;
    return 0;
}