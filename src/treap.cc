// Copyright 2019 Yan Song

#include "streamingcc_include/treap.h"

using streamingcc::util::rand_double;

namespace streamingcc {

// Underlying insertion and searching
template <typename T>
bool Treap<T>::contains(treeNode<T>* tn, T val) {
    // base case
    if (tn == nullptr) return false;
    // hit
    if (tn->value == val) return true;
    // Go to left subtree
    if (tn->value > val) return contains(tn->lc, val);
    // Go to right subtree
    return contains(tn->rc, val);
}

template <typename T>
treeNode<T>* Treap<T>::insert(treeNode<T>* tn, T val) {
    // Empty tree
    if (_size == 0) {
        root->value = val;
        assignPriority(root);
        _size++;
        return root;
    }

    // Insert to the left
    if (tn->value >= val) {
        if (tn->lc == nullptr) {
            // Create a new left child
            treeNode<T>* nlc = new treeNode<T>();
            _size++;
            assignPriority(nlc);
            nlc->value = val;
            // Connect nlc to tree
            nlc->parent = tn;
            tn->lc = nlc;
            // Adjust height and priority
            nlc->height = 0;
            updateHeight(tn);
            adjustPriority(nlc);
            return nlc;
        }
        return insert(tn->lc, val);
    }

    // Insert to the right
    if (tn->rc == nullptr) {
        // Create a new right child
        treeNode<T>* nrc = new treeNode<T>();
        _size++;
        assignPriority(nrc);
        nrc->value = val;
        // Connect nrc to tree
        nrc->parent = tn;
        tn->rc = nrc;
        // Adjust height
        nrc->height = 0;
        updateHeight(tn);
        adjustPriority(nrc);
        return nrc;
    }
    return insert(tn->rc, val);
}

// Rotation
template <typename T>
void Treap<T>::rotate(treeNode<T> *tn) {
    if (tn->parent == nullptr) return;
    if (tn->parent->lc == tn) return rotate_right(tn);
    return rotate_left(tn);
}

template <typename T>
void Treap<T>::rotate_left(treeNode<T> *y) {
    treeNode<T>* x = y->parent;
    treeNode<T>* z = y->lc;

    // Take care of x's parent
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x->parent->lc == x) {
        x->parent->lc = y;
    } else {
        x->parent->rc = y;
    }

    // work on y
    y->parent = x->parent;
    y->lc = x;

    // work on x
    x->parent = y;
    x->rc = z;

    // work on z
    if (z != nullptr) z->parent = x;

    updateHeight(y);
    updateHeight(x);
}

template <typename T>
void Treap<T>::rotate_right(treeNode<T> *x) {
    treeNode<T>* y = x->parent;
    treeNode<T>* z = x->rc;

    // Take care of y's parent
    if (y->parent == nullptr) {
        this->root = x;
    } else if (y->parent->lc == y) {
        y->parent->lc = x;
    } else {
        y->parent->rc = x;
    }

    // work on x
    x->parent = y->parent;
    x->rc = y;

    // work on y
    y->parent = x;
    y->lc = z;

    // work on z
    if (z != nullptr) z->parent = y;

    updateHeight(x);
    updateHeight(y);
}

// Helper functions
template <typename T>
void Treap<T>::updateHeight(treeNode<T> *tn) {
    if (tn == nullptr) return;

    int oldHeight = tn->height;
    int newHeight = 0;
    if (tn->lc == nullptr && tn->rc == nullptr) newHeight = 0;
    else if (tn->lc == nullptr) newHeight = tn->rc->height + 1;
    else if (tn->rc == nullptr) newHeight = tn->lc->height + 1;
    else if (tn->lc->height > tn->rc->height)
        newHeight = tn->lc->height + 1;
    else
        newHeight = tn->rc->height + 1;

    if (newHeight == oldHeight) {
        return;
    } else {
        tn->height = newHeight;
        updateHeight(tn->parent);
    }
}

template <typename T>
void Treap<T>::adjustPriority(treeNode<T> *x) {
    while (x->parent != nullptr && x->priority > x->parent->priority) {
        rotate(x);
    }
}

template <typename T>
void Treap<T>::assignPriority(treeNode<T>* tn) {
    double randomPriority = rand_double(1.0);
    if (static_cast<int>(randomPriority) == 1) assignPriority(tn);
    else
        tn->priority = randomPriority;
}

template <typename T>
void Treap<T>::destroyRecursive(treeNode<T>* tn) {
    if (tn == nullptr)
        return;

    destroyRecursive(tn->lc);
    destroyRecursive(tn->rc);
    delete tn;
}

}  // namespace streamingcc
