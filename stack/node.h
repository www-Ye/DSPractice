#ifndef NODE_H
#define NODE_H

typedef char Node_entry;

struct Node{
    // data members
    Node_entry entry;
    Node* next;
    // constructors
    Node();
    Node(Node_entry item, Node* add_on = nullptr);
};

#endif