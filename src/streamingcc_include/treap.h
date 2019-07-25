#ifndef STREAMINGCC_TREAP_H
#define STREAMINGCC_TREAP_H

#include <random>
#include <ctime>

namespace streamingcc {

template <typename T>
// struct for tree node to store single data of
// any comparable type
struct treeNode {
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
    treeNode(T value, int height, double priority) {
        treeNode();
        this->value = value;
        this->height = height;
        this->priority = priority;
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

    // Insertion below a treeNode
    treeNode<T>* insert(treeNode<T>* tn, T val);

    // Helper functions
    void assignPriority(treeNode<T>* tn);
    void updateHeight(treeNode<T>* tn);
    void adjustPriority(treeNode<T>* tn);

public:
    // Constructor
    Treap() {
        this->root = new treeNode<T>();
        this->_size = 0;
    }
    // Deconstructor
    ~Treap() {};

    void insert(T val) { insert(this->root, val); };
    treeNode<T>* find(T val);
};

}
#endif //STREAMINGCC_TREAP_H
