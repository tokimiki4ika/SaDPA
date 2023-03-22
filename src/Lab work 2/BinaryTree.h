#ifndef SADPA_BINARYTREE_H_
#define SADPA_BINARYTREE_H_

#include <utility>

template <class Key>
class BinaryTree {
 public:
  struct Node {
    Key key;
    std::size_t Height = 1;
    Node* left{};
    Node* right{};
    Node(Key k) : key(k) {}
    ~Node() {
      delete left;
      delete right;
    }
  };

 private:
  unsigned char Height(Node* current) { return current ? current->Height : 0; }

  int BalanceFactor(Node* current) {
    return Height(current->right) - Height(current->left);
  }

  void FixHeight(Node* current) {
    unsigned char hl = Height(current->left);
    unsigned char hr = Height(current->right);
    current->Height = (hl > hr ? hl : hr) + 1;
  }

  Node* RotateRight(Node* current) {
    Node* q = current->left;
    current->left = q->right;
    q->right = current;
    FixHeight(current);
    FixHeight(q);
    return q;
  }

  Node* RotateLeft(Node* q) {
    Node* current = q->right;
    q->right = current->left;
    current->left = q;
    FixHeight(q);
    FixHeight(current);
    return current;
  }

  Node* balance(Node* current) {
    FixHeight(current);
    if (BalanceFactor(current) == 2) {
      if (BalanceFactor(current->right) < 0)
        current->right = RotateRight(current->right);
      return RotateLeft(current);
    }
    if (BalanceFactor(current) == -2) {
      if (BalanceFactor(current->left) > 0)
        current->left = RotateLeft(current->left);
      return RotateRight(current);
    }
    return current;
  }

  Node* FindMin(Node* current) {
    return current->left ? FindMin(current->left) : current;
  }

  Node* RemoveMin(Node* current) {
    if (current->left == 0) return current->right;
    current->left = RemoveMin(current->left);
    return balance(current);
  }

  Node* insert_node(Node* current, Key k) {
    if (!current) return new Node(k);
    if (k < current->key)
      current->left = insert_node(current->left, k);
    else
      current->right = insert_node(current->right, k);
    return balance(current);
  }

  Node* remove(Node* current, Key k) {
    if (!current) return nullptr;
    if (k < current->key)
      current->left = remove(current->left, k);
    else if (k > current->key)
      current->right = remove(current->right, k);
    else {
      Node* q = std::exchange(current->left, nullptr);
      Node* r = std::exchange(current->right, nullptr);
      delete current;
      if (!r) return q;
      Node* min = FindMin(r);
      min->right = RemoveMin(r);
      min->left = q;
      return balance(min);
    }
    return balance(current);
  }

  bool find_node(Node* current, Key k) {
      if (!current) return false;
      if (current->key > k) {
          return find_node(current->left, k);
      } else if (current->key < k) {
          return find_node(current->right, k);
      } else {
          return true;
      }
  }

    Node* _root{};
    std::size_t _size{};

 public:
  BinaryTree() = default;
  BinaryTree(std::initializer_list<Key> &items) {
      for (Key item : items) {
          _root = insert_node(_root, item);
          ++_size;
      }
  }
  ~BinaryTree() { delete _root; }
  
  void insert(Key k) {
      _root = insert_node(_root, k);
  }

  void erase(Key k) {
      _root = remove(_root, k);
  }

  bool find(Key k) {
      return find_node(_root, k);
  }
};

#endif  // SADPA_BINARYTREE_H_
