template <class Record>
void AVL_node<Record>::set_balance(Balance_factor b)
{
	balance = b;
}

template <class Record>
Balance_factor AVL_node<Record>::get_balance() const
{
	return balance;
}

template <class Record>
Error_code AVL_tree<Record>::insert(const Record &new_data)
{
	bool taller;
	return avl_insert(root, new_data, taller);
}

template <class Record>
Error_code AVL_tree<Record>::avl_insert(Binary_node<Record>* &sub_root,
			const Record &new_data, bool taller)
{
	Error_code result = success;
	if(sub_root == NULL){
		sub_root = new AVL_node<Record>(new_data);
		taller = true;
	}else if(new_data == sub_root->data){
		result = duplicate_error;
		taller = false;
	}else if(new_data < sub_root->data){
		result = avl_insert(sub_root-left, new_data, taller);
		if(taller == true)
			switch(sub_root->get_balance()){
			case left_higher:
				left_balance(sub_root);
				taller = false;
				break;
			case equal_height:
				sub_root->set_balance(left_higher);
				break;
			case right_higher:
				sub_root->set_balance(equal_height);
				taller = false;
				break;
			}
	}else{
		result = avl_insert(sub_root->right, new_data, taller);
		if(taller == true)
			switch(sub_root->get_balance()){
			case left_higher:
				sub_root->set_balance(equal_height);
				taller = false;
				break;
			case equal_height:
				sub_root->set_balance(right_higher);
				break;
			case right_higher:
				right_balance(sub_root);
				taller = false;
				break;
			}
	}
	return result;
}

template <class Record>
void AVL_tree<Record>::rotate_left(Binary_node<Record>* &sub_root)
{
	if(sub_root == NULL || sub_root->right == NULL)
		cout << "WARNING: program error detected in rotate left" << endl;
	else{
		Binary_node<Record>* right_tree = sub_root->right;
		sub_root->right = right_tree->left;
		right_tree->left = sub_root;
		sub_root = right_tree;
	}
}

template <class Record>
void AVL_tree<Record>::right_balance(Binary_node<Record>* &sub_root)
{
	Binary_node<Record>* &right_tree = sub_root->right;
	switch(right_tree->get_balance()){
	case right_higher:
		sub_root->set_balance(equal_height);
		right_tree->set_balance(equal_height);
		rotate_left(sub_root);
		break;
	case equal:
		cout << "WARNING: program error detected in right_balance" << endl;
	case left_higher:
		Binary_node<Record>* sub_tree = right_tree->left;
		switch(sub_tree->get_balance()){
		case equal_height:
			sub_root->set_balance(equal_height);
			right_tree->get_balance(equal_height);
			break;
		case left_higher:
			sub_root->set_balance(equal_height);
			right_tree->set_balance(right_balance);
			break;
		case right_higher:
			sub_root->set_balance(left_higher);
			right_tree->set_balance(equal_height);
			break;
		}
		sub_tree->set_balance(equal_height);
		rotate_right(right_tree);
		rotate_left(sub_root);
		break;
	}
}