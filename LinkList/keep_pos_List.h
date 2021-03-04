template <class Node_entry>
struct Node{
	// data members
	Node_entry entry;
	Node<Node_entry>* next;
	// constructors
	Node();
	Node(Node_entry, Node<Node_entry>* link = NULL);
};

template <class List_entry>
class List{
public:
	List();
	int size() const;
	bool full() const;
	bool empty() const;
	void clear();
	void traverse(void (*visit)(List_entry &));
	Error_code retrieve(int position, List_entry &x) const;
	Error_code replace(int position, const List_entry &x);
	Error_code remove(int position, List_entry &x);
	Error_code insert(int position, const List_entry &x);
	~List();
	List(const List<List_entry> &copy);
	void operator= (const List<List_entry> &copy);
protected:
	int count;
	mutable int current_position;
	Node<List_entry>* head;
	mutable Node<List_entry>* current;
	// Auxiliary function to locate list positions follows:
	Node<List_entry>* set_position(int position) const;
};