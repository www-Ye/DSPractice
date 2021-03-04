template <class Entry>
struct Binary_node{
	Entry data;
	Binary_node<Entry> *left;
	Binary_node<Entry> *right;
	
	Binary_node();
	Binary_node(const Entry &x);
	
	virtual void set_balance(Balance_factor b);
	virtual Balance_factor get_balance() const;
};