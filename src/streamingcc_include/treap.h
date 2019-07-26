// Copyright 2019 Yan Song

#ifndef SRC_STREAMINGCC_INCLUDE_TREAP_H_
#define SRC_STREAMINGCC_INCLUDE_TREAP_H_

#include "../streamingcc_include/util.h"

namespace streamingcc {

template <typename T>
// struct for tree node to store single data of
// any comparable type
struct treeNode {
 public:
    treeNode* parent;
    treeNode* lc;
    treeNode* rc;
    T value;
    int height;
    double priority;

    // Constructor
    treeNode() {
        parent = nullptr;
        lc = nullptr;
        rc = nullptr;
        height = 0;
    }
};

template <typename T>
class Treap {
    // Private data in treap
    treeNode<T>* root;
    int _size;

    // Private operations
    // Rotation
    void rotate(treeNode<T>* tn);
    void rotate_left(treeNode<T>* tn);
    void rotate_right(treeNode<T>* tn);

    // Underlying insertion and searching
    treeNode<T>* insert(treeNode<T>* tn, T val);
    bool contains(treeNode<T>* tn, T val);

    // Helper functions
    void assignPriority(treeNode<T>* tn);
    void updateHeight(treeNode<T>* tn);
    void adjustPriority(treeNode<T>* tn);

    // Clear treap
    void destroyRecursive(treeNode<T>* tn);

 public:
    // Constructor
    Treap() {
        root = new treeNode<T>();
        _size = 0;
    }
    // Destructor
    ~Treap() { destroyRecursive(this->root); }

    void insert(T val) { insert(this->root, val); }
    bool contains(T val) { return contains(this->root, val); }
};


}  // namespace streamingcc
#endif  // SRC_STREAMINGCC_INCLUDE_TREAP_H_

