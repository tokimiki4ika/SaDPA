#include "HashMap.h"


class HashNode {
public:
    int key;
    std::string value;
    HashNode* next;

    HashNode(int key, std::string value) {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};

HashMap::HashMap() {
    table.resize(TABLE_SIZE, NULL);
}

int HashMap::hash(int key) {
    srand(time(NULL));
    int random_num = rand() % 10000;

    int hash_code = key ^ random_num;

    return hash_code % TABLE_SIZE;
}

void HashMap::insert(int key, std::string value) {
    int index = hash(key);
    HashNode* node = new HashNode(key, value);

    if (table[index] == NULL) {
        table[index] = node;
    } else {
        HashNode* current = table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

std::string HashMap::get(int key) {
    int index = hash(key);
    HashNode* current = table[index];

    while (current != NULL) {
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
    HashNode* prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
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
