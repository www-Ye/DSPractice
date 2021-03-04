class Extended_stack{
public:
	Extended_stack();
	Error_code pop();
	Error_code top(Stack_entry &item) const;
	Error_code push(const Stack_entry &item);
	bool empty() const;
	void clear();
	bool full() const;
	int size() const;
private:
	int count;
	Stack_entry entry[maxstack];
};