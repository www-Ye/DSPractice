const int num_chars = 28;
struct Trie_node{
	// data members
	Record* data;
	Trie_node* branch[num_chars];
	// constructors
	Trie_node();
}

class Trie{
public:

private:
	Trie_node* root;
}