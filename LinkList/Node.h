template <class Node_entry>
struct Node{
	// data members
	Node_entry entry;
	Node<Node_entry>* next;
	// constructors
	Node();
	Node(Node_entry, Node<Node_entry>* link = NULL);
};
