#include <iostream>
#include <ctime>
#include "BinaryTree.h"

int main() {
    BinaryTree<int> a;
    int N;
    std::cout << "Enter a count of element for insert in tree:" << std::endl;
    std::cin >> N;
    for (int i = 1; i < N; i++) {
        a.insert(std::rand());
    }
    a.insert(5);
    std::cout << "Elements in tree: " << N << std::endl;
    char oper{};
    std::clock_t tmp{};
    do {
        std::cout << "Insert character for operation: I/i - insert element, F/f - find element, E/e - erase element, C - exit" << std::endl;
        std::cin >> oper;
        if (oper >= 'a') {
            oper -= 32;
        }
        switch (oper) {
            case 'I':
                std::cout << "Write element for insert: " << std::endl;
                std::cin >> N;
                tmp = std::clock();
                a.insert(N);
                std::cout << "Duration: " << (clock() - tmp) << " ms" << std::endl;
                break;
            case 'F':
                std::cout << "Write element for find: " << std::endl;
                std::cin >> N;
                tmp = std::clock();
                if (a.find(N)) {
                    std::cout << "Element is contain" << std::endl;
                } else {
                    std::cout << "In tree haven't this element" << std::endl;
                }
                std::cout << "Duration: " << (clock() - tmp) << " ms" << std::endl;
                break;
            case 'E':
                std::cout << "Write element for erase: " << std::endl;
                std::cin >> N;
                tmp = std::clock();
                a.erase(N);
                std::cout << "Duration: " << (clock() - tmp) << " ms" << std::endl;
                break;
            default:
                continue;
        }
    } while (oper != 'C');
}