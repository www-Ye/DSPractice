#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Binary_node.h"

template <class Entry>
class Binary_tree{
public:
    Binary_tree();
    bool empty() const;
    void preorder(void (*visit)(Entry &));
    void inorder(void (*visit)(Entry &));
    void postorder(void (*visit)(Entry &));
    int size() const;
    void clear();
    int height() const;
protected:
    Binary_node<Entry> *root;
}

#endif