#include "Node.h"

template <class Node_entry>
Node<Node_entry>::Node(){
	next = nullptr;
}

template <class Node_entry>
Node<Node_entry>::Node(Node_entry data, Node<Node_entry>* link){
	entry = data;
	next = link;
}
