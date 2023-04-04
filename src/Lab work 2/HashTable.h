#ifndef SADPA_HASHTABLE_H_
#define SADPA_HASHTABLE_H_

#include <cstdlib>
#include <string>
#include <vector>

class HashTable {
    struct HashNode;
 public:
    HashTable();
    HashTable(std::size_t size);
    ~HashTable();
  void insert(int key, std::string value);
  std::string &operator[](int key);
  void erase(int key);
  void clear();
  void reserve(std::size_t size);
  std::string at(int key);
  std::size_t capacity();
    std::size_t size();

private:
    struct HashNode {
        int key{};
        std::string value{};
        HashNode* next{};

        HashNode() = default;
        HashNode(int key, std::string value) {
            this->key = key;
            this->value = std::move(value);
        }
        ~HashNode() {
            delete next;
        }
    };

    int hash(int key);
  HashNode** _table{};
  std::size_t _capacity{}, _size{};
  int hash_num{};
};

#endif  // SADPA_HASHTABLE_H_
