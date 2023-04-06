#ifndef SADPA_DEQUE_H_
#define SADPA_DEQUE_H_

#include <stdexcept>
#include <utility>

template <class Key>
class Deque {
    struct Node {
        Node() = default;
        Node(Key _value, Node *_prev = nullptr, Node *_next = nullptr) : value(_value), next(_next), prev(_prev) {
            if (next) {
                next->prev = this;
            }
            if (prev) {
                prev->next = this;
            }
        }
        ~Node() {
            delete next;
        }
        Key value;
        Node *next{}, *prev{};
    };
public:
    Deque() {
        _begin = _end = new Node();
    }
    ~Deque() {
        delete _begin;
    }
    void push_front(Key key) {
        _begin = new Node(key, nullptr, _begin);
        ++_size;
    }
    void push_back(Key key) {
        if (empty()) {
            push_front(key);
        } else {
            new Node(key, _end->prev, _end);
            ++_size;
        }
    }
    void pop_front() {
        CheckSize();
        Node *tmp = _begin;
        _begin = _begin->next;
        tmp->next = _begin->prev = nullptr;
        delete tmp;
        --_size;
    }
    void pop_back() {
        CheckSize();
        if (!(--_size)) {
            _begin->next = nullptr;
            delete _begin;
            _begin = _end;
        } else {
            Node *tmp = _end->prev;
            tmp->prev->next = _end;
            _end->prev = tmp->prev;
            tmp->next = nullptr;
            delete tmp;
        }
    }
    Key &front() {
        CheckSize();
        return _begin->value;
    }
    Key &back() {
        CheckSize();
        return _end->prev->value;
    }
    std::size_t size() { return _size; }
    bool empty() { return _size == 0; }
private:
    void CheckSize() {
        if (empty()) {
            throw std::invalid_argument("Deque is empty");
        }
    }
    Node *_begin, *_end;
    std::size_t _size{};
};

#endif //SADPA_DEQUE_H_
