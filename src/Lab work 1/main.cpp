#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include "InsertionSort.h"
#include "QuickSort.h"

int main() {
    std::vector<int> insert, quick, std_sort;
    int N{};
    std::cout << "Enter size of array:";
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp = std::rand();
        insert.push_back(tmp);
        quick.push_back(tmp);
        std_sort.push_back(tmp);
    }
    std::cout << "Elements in array: " << N << std::endl << std::endl;

    std::clock_t start = std::clock();
    QuickSort<std::vector<int>::iterator>(quick.begin(), quick.end());
    std::cout << "Quick Sort Duration: " << (std::clock() - start) << " ms" << std::endl;

    start = std::clock();
    InsertionSort<std::vector<int>::iterator>(insert.begin(), insert.end());
    std::cout << "Insertion Sort Duration: " << (std::clock() - start) << " ms" << std::endl;

    start = std::clock();
    std::sort<std::vector<int>::iterator>(std_sort.begin(), std_sort.end());
    std::cout << "Std Sort Duration: " << (std::clock() - start) << " ms" << std::endl;
}
