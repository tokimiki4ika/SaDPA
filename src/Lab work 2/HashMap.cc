#include "HashMap.h"

#include <utility>

class HashNode {
 public:
  int key;
  std::string value;
  HashNode* next;

  HashNode(int key, std::string value) {
    this->key = key;
    this->value = std::move(value);
    this->next = nullptr;
  }
};

HashMap::HashMap() { table.resize(TABLE_SIZE, nullptr); }

int HashMap::hash(int key) {
  std::srand(time(nullptr));
  int random_num = std::rand() % 10000;

  int hash_code = key ^ random_num;

  return hash_code % TABLE_SIZE;
}

void HashMap::insert(int key, std::string value) {
  int index = hash(key);
  HashNode* node = new HashNode(key, std::move(value));

  if (table[index] == nullptr) {
    table[index] = node;
  } else {
    HashNode* current = table[index];
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = node;
  }
}

std::string HashMap::get(int key) {
  int index = hash(key);
  HashNode* current = table[index];

  while (current != nullptr) {
    if (current->key == key) {
      return current->value;
    }
    current = current->next;
  }

  return "Key not found";
}

void HashMap::remove(int key) {
  int index = hash(key);
  HashNode* current = table[index];
  HashNode* prev = nullptr;

  while (current != nullptr) {
    if (current->key == key) {
      if (prev == nullptr) {
        table[index] = current->next;
      } else {
        prev->next = current->next;
      }
      delete current;
      return;
    }
    prev = current;
    current = current->next;
  }
}
