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
void QuickSort(T first, T last) {
    if (std::distance(first, last) > 1){
        T bound = Partition<T, Compare>(first, last);
        QuickSort<T, Compare>(first, bound);
        QuickSort<T, Compare>(bound + 1, last);
    }
}


#endif //LAB_WORK_1_QUICKSORT_H_
