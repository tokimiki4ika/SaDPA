#ifndef SADPA_HASHMAP_H_
#define SADPA_HASHMAP_H_

#include <cstdlib>
#include <string>
#include <vector>

class HashNode;

class HashMap {
  static constexpr int TABLE_SIZE = 1000;

 public:
  HashMap();

  int hash(int key);

  void insert(int key, std::string value);
  std::string get(int key);
  void remove(int key);

 private:
  std::vector<HashNode*> table;
};

#endif  // SADPA_HASHMAP_H_
