#ifndef LAB_WORK_1_INSERTIONSORT_H_
#define LAB_WORK_1_INSERTIONSORT_H_

#include <functional>

template <class T, class Compare = std::less<>>
void InsertionSort(T begin, T end) {
    for(T i = begin + 1; i < end; ++i) {
        for(T j = i; j > begin && Compare{}(*j, *(j - 1)); --j) {
            std::swap(*(j - 1), *j);
        }
    }
}

#endif //LAB_WORK_1_INSERTIONSORT_H_
