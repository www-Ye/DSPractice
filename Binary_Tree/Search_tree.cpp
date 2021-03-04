template <class Record>
Binary_node<Record>* Search_tree<Record>::search_for_node(
	Binary_node<Record>* sub_root, const Record &target) const
{
	if(sub_root == NULL || sub_root->data == target) return sub_root;
	else if(sub_root->data < target)
		return search_for_node(sub_root->right, target);
	else return search_for_node(sub_root->left, target);
}

template <class Record>
Error_code Search_tree<Record>::tree_search(Record &target) const
{
	Error_code result = success;
	Binary_node<Record>* found = search_for_node(root, target);
	if(found == NULL)
		result = not_present;
	else
		target = found->data;
	return;
}

template <class Record>
Error_code Search_tree<Record>::insert(const Record &new_data)
{
	return search_and_insert(root, new_data);
}

template <class Record>
Error_code Search_tree<Record>::search_and_insert(
	Binary_node<Record>* &sub_root, const Record &new_data)
{
	if(sub_root == NULL){
		sub_root = new Binary_node<Record>(new_data);
		return success;
	}
	else if(new_data < sub_root->data)
		return search_and_insert(sub_root->left, new_data);
	else if(new_data > sub_root->data)
		return search_and_insert(sub_root->right, new_data);
	else return duplicate_error;
}

template <class Record>
Error_code Search_tree<Record>::remove(const Record &target)
{
	return search_and_destroy(root, target);
}

template <class Record>
Error_code Search_tree<Record>::search_and_destroy(
			Binary_node<Record>* &sub_root, const Record &target)
{
	if(sub_root == NULL || sub_root->data == target)
		return remove_root(sub_root);
	else if(target < sub_root->data)
		return search_and_destroy(sub_root->left, target);
	else
		return search_and_destroy(sub_root->right, target);
}

template <class Record>
Error_code Search_tree<Record>::remove_root(Binary_node<Record>* &sub_root)
{
	if(sub_root == NULL) return not_present;
	Binary_node<Record>* to_delete = sub_root;
	
	if(sub_root->right == NULL) sub_root = sub_root->left;
	else if(sub_root->left == NULL) sub_root = sub_root->right;
	else{
		to_delete = sub_root->left;
		Binary_node<Record>* parent = sub_root;
		while(to_delete->right != NULL){
			parent = to_delete;
			to_delete = to_delete->right;
		}
		sub_root->data = to_delete->data;
		if(parent == sub_root) sub_root->left = to_delete->left;
		else parent->right = to_delete->left;
	}
	delete to_delete;
	return success;
}