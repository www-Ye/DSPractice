#ifndef _NODE_H
#define _NODE_H

template <class Node_entry>
struct Node{
	// data members
	Node_entry entry;
	Node<Node_entry>* next;
	// constructors
	Node();
	Node(Node_entry data, Node<Node_entry>* link = nullptr);
};

template <class Node_entry>
Node<Node_entry>::Node(){
	next = nullptr;
}

template <class Node_entry>
Node<Node_entry>::Node(Node_entry data, Node<Node_entry>* link){
	entry = data;
	next = link;
}

#endif
