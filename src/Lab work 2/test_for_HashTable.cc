#include <ctime>
#include <iostream>

#include "HashTable.h"

int main() {
    HashTable a(5);
    int N;
    char oper{};
    std::clock_t tmp{};
    std::string tmp_str{};
    do {
        std::cout << "Insert character for operation: I/i - insert element, A/a - Insert or access, F/f - find element, E/e - erase element, C - exit" << std::endl;
        std::cin >> oper;
        if (oper >= 'a') {
            oper -= 32;
        }
        switch (oper) {
            case 'I':
                std::cout << "Write element and value for insert(example - 32 hello): " << std::endl;
                std::cin >> N >> tmp_str;
                tmp = std::clock();
                a.insert(N, tmp_str);
                std::cout << "Duration: " << (clock() - tmp) << " ms" << std::endl;
                break;
            case 'F':
                std::cout << "Write element for find: " << std::endl;
                std::cin >> N;
                tmp = std::clock();
                try {
                    tmp_str = a.at(N);
                    std::cout << "Found value for key " << N << ": " << tmp_str << std::endl;
                } catch (const std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "Duration: " << (clock() - tmp) << " ms" << std::endl;
                break;
            case 'A':
                std::cout << "Write element and value for insert(example - 32 hello): " << std::endl;
                std::cin >> N >> tmp_str;
                tmp = std::clock();
                a[N] = tmp_str;
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
                break;
        }
        std::cout << "size: " << a.size() << " capacity: " << a.capacity() << std::endl;
    } while (oper != 'C');
    return 0;
}
