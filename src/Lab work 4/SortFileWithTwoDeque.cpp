#include <iostream>
#include <fstream>

#include "Deque.h"

void InsertSortFirstDeque(Deque<std::string> &first, Deque<std::string> &second, std::string src) {
    while (!first.empty()) {
        if (first.back() > src) {
            second.push_front(first.back());
            first.pop_back();
        } else {
            first.push_back(src);
            break;
        }
    }
    if (first.empty()) {
        first.push_back(src);
    }
}

void InsertSortSecondDeque(Deque<std::string> &first, Deque<std::string> &second, std::string src) {
    while (!second.empty()) {
        if (second.front() < src) {
            first.push_back(second.front());
            second.pop_front();
        } else {
            second.push_front(src);
            break;
        }
    }
    if (second.empty()) {
        second.push_front(src);
    }
}

int main() {
    Deque<std::string> first{}, second{};

    std::string line;

    std::ifstream in("input.txt");
    if (in.is_open()) {
        int i{};
        while (getline(in, line)) {
            if (first.empty()) {
                InsertSortSecondDeque(first, second, line);
            } else if (second.empty()) {
                InsertSortFirstDeque(first, second, line);
            } else if (second.front() < line) {
                InsertSortSecondDeque(first, second, line);
            } else {
                InsertSortFirstDeque(first, second, line);
            }
        }
    }
    in.close();
    while (!first.empty()) {
        std::cout << first.front() << std::endl;
        first.pop_front();
    }
    while (!second.empty()) {
        std::cout << second.front() << std::endl;
        second.pop_front();
    }
    return 0;
}
