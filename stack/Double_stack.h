const int maxstack = 10;

class Double_stack{
public:
	Double_stack();
	Error_code top_a(Stack_entry &item) const;
	Error_code top_b(Stack_entry &item) const;
	Error_code push_a(const Stack_entry &item);
	Error_code push_b(const Stack_entry &item);
	Error_code pop_a();
	Error_code pop_b();
	bool empty_a() const;
	bool empty_b() const;
private:
	int count_a, count_b;
	Stack_entry entry[maxstack];
};