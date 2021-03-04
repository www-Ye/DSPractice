template <class Record, int order>
class B_tree{
pulbic:
private:
	B_node<Record, order>* root;
	
};

template <class Record, int order>
struct B_node{
	int count;
	Record data[order - 1];
	B_node<Record, order>* branch[order];
	
	B_node();
};