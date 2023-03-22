#include <ctime>
#include <iostream>
#include "HashMap.h"

int main() {
    HashMap my_map;

    my_map.insert(5, "hello");
    my_map.insert(15, "world");
    my_map.insert(25, "foo");
    my_map.insert(35, "bar");
    my_map.insert(45, "baz");

    std::cout << my_map.get(15) << std::endl;
    std::cout << my_map.get(35) << std::endl;

    my_map.remove(35);

    std::cout << my_map.get(35) << std::endl;
    return 0;
}
