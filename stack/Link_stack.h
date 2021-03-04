class Stack{
public:
	Stack();
	bool empty() const;
	Error_code push(const Stack_entry &item);
	Error_code pop();
	Error_code top(Stack_entry &item) const;
	// Safety features for linked structures
	~Stack();
	Stack(const Stack &original);
	void operator =(const Stack &original);
protected:
	Node* top_node;
};