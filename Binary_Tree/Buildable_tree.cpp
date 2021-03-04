template <class Record>
Error_code Buildable_tree<Record>::bulid_tree(const List<Record> &supply)
{
	Error_code ordered_data = success;		// Set this to fail if keys do not increase.
	int count = 0;
	Record x, last_x;
	List<Binary_node<Record>* > last_node;
	
	Binary_node<Record>* none = NULL;
	last_node.insert(0, none);
	while(supply.retrieve(count, x) == success){
		if(count > 0 && x <= last_x){
			ordered_data = fail;
			break;
		}
		build_insert(++count, x, last_node);
		last_x = s;
	}
	root = find_root(last_node);
	connect_trees(last_node);
	return ordered_data;
}

template <class Record>
void Buildable_tree<Record>::build_insert(int count
							 const Record &new_data,
							 List<Binary_node<Record>* > &last_node)
{
	int level;
	for(level = 1; count % 2 == 0; level++)
		count /= 2;
	Binary_node<Record> *next_node = new Binary_node<Record>(new_data),
						*parent;
	last_node.retrieve(level - 1, next_node->left);
	if(last_node.size() <= level)
		last_node.insert(level, next_node);
	else
		last_node.replace(level, next_node);
	if(last_node.retrieve(level + 1, parent) == success && parent->right == NULL)
		parent->right = next_node;
}