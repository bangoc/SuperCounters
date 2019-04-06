#include "slist.h"

#include <iostream>
#include <type_traits>

template<typename T>
using my_value_t = typename std::enable_if_t<
        std::is_integral<
            typename std::iterator_traits<T>::value_type>::value,
        typename std::iterator_traits<T>::value_type>;

template<typename T>
int MyCount(T begin, T end, my_value_t<T> value) {
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
    SList<float> list2 = {one, one, 2, 3, 5};

    // Error:: it is not safe to compare floating numbers
    std::cout << MyCount(list2.begin(), list2.end(), 1.0f) << std::endl;
    return 0;
}