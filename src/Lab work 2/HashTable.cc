#include <stdexcept>

#include "HashTable.h"

HashTable::HashTable() { reserve(10); }


HashTable::HashTable(std::size_t size) {
    reserve(size);
}

HashTable::~HashTable() {
    clear();
    delete[] _table;
}

int HashTable::hash(int key) {
  return (key ^ hash_num) % _capacity;
}

std::size_t HashTable::capacity() {
    return _capacity;
}

std::size_t HashTable::size() {
    return _size;
}

void HashTable::insert(int key, std::string value) {
  if (_size  > _capacity * 0.75) {
      reserve(_capacity * 2);
  }
  int index = hash(key);

  if (_table[index] == nullptr) {
      _table[index] = new HashNode(key, std::move(value));
  } else {
    HashNode* current = _table[index];
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new HashNode(key, std::move(value));
  }
  ++_size;
}

void HashTable::clear() {
    for (std::size_t i{}; i < _capacity; ++i) {
        delete _table[i];
        _table[i] = nullptr;
    }
    _size = 0;
}

void HashTable::reserve(std::size_t size) {
    hash_num = std::rand() % size;
    if (!size) {
        throw std::logic_error("Can't set size less then 1");
    } else if (_capacity == 0) {
        _table = new HashNode*[size]{};
        _capacity = size;
    } else {
        _size = 0;
        HashNode** tmp_table = std::move(_table);
        _table = new HashNode*[size]{};
        std::size_t capacity = _capacity;
        _capacity = size;
        for (std::size_t i{}; i < capacity; ++i) {
            if (tmp_table[i]) {
                HashNode* tmp_node = tmp_table[i];
                while (tmp_node) {
                    insert(tmp_node->key, tmp_node->value);
                    tmp_node = tmp_node->next;
                }
            }
            delete tmp_table[i];
        }
        delete[] tmp_table;
    }
}

std::string& HashTable::operator[](int key) {
  int index = hash(key);
  HashNode* current = _table[index];

  while (current != nullptr) {
    if (current->key == key) {
      return current->value;
    }
    current = current->next;
  }
  insert(key, std::string{});
  return (*this)[key];
}

std::string HashTable::at(int key) {
    int index = hash(key);
    HashNode* current = _table[index];
    if (current == nullptr) {
        throw std::invalid_argument("Haven't key in table");
    }
    while (current) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return current->value;
}

void HashTable::erase(int key) {
  int index = hash(key);
  HashNode* current = _table[index], *prev{};

  while (current) {
    if (current->key == key) {
      if (!prev) {
          _table[index] = current->next;
      } else {
        prev->next = current->next;
      }
      current->next = nullptr;
      delete current;
      --_size;
      break;
    }
    prev = current;
    current = current->next;
  }
}
