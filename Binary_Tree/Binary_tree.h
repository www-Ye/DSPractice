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
	void insert(const Entry &);
	Binary_tree(const Binary_tree<Entry> &original);
	Binary_tree & operator = (const Binary_tree<Entry> &original);
	~Binary_tree();
protected:
	Binary_node<Entry> *root;
};