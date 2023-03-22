#ifndef LAB_WORK_1_QUICKSORT_H_
#define LAB_WORK_1_QUICKSORT_H_

#include <functional>

template <class T, class Compare>
T Partition(T first, T last)
{
    auto base = std::prev(last, 1);
    auto i = first;
    for (auto j = first; j != base; ++j){
        if (Compare{}(*j, *base)){
            std::swap(*i++, *j);
        }
    }
    std::swap(*i, *base);
    return i;
}

template <class T, class Compare = std::less<>>
void QuickSort(T begin, T end) {
    if (std::distance(begin, end) > 1){
        T bound = Partition<T, Compare>(begin, end);
        QuickSort<T, Compare>(begin, bound);
        QuickSort<T, Compare>(bound + 1, end);
    }
}


#endif //LAB_WORK_1_QUICKSORT_H_
