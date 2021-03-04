//
// File: Binary_tree.cpp
// Desc:
// Author: wy
//

template <class Entry>
Binary_tree<Entry>::Binary_tree()
{
	root = NULL;
}

template <class Entry>
bool Binary_tree<Entry>::empty() const
{
	return root == NULL;
}

template <class Entry>
void Binary_tree<Entry>::inorder(void (*visit)(Entry &))
{
	recursive_inorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry>::preorder(void (*visit)(Entry &))
{
	recursive_preorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry>::postorder(void (*visit)(Entry &))
{
	recursive_postorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry>::recursive_inorder(Binary_node<Entry> *sub_root,
										   void (*visit)(Entry &))
{
	if(sub_root != NULL){
		recursive_inorder(sub_root->left, visit);
		(*visit)(sub_root->data);
		recursive_inorder(sub_root->right, visit);
	}
}

template <class Entry>
void Binary_tree<Entry>::recursive_preorder(Binary_node<Entry> *sub_root,
										   void (*visit)(Entry &))
{
	if(sub_root != NULL){
		(*visit)(sub_root->data);
		recursive_inorder(sub_root->left, visit);
		recursive_inorder(sub_root->right, visit);
	}
}

template <class Entry>
void Binary_tree<Entry>::recursive_postorder(Binary_node<Entry> *sub_root,
										   void (*visit)(Entry &))
{
	if(sub_root != NULL){
		recursive_inorder(sub_root->left, visit);
		recursive_inorder(sub_root->right, visit);
		(*visit)(sub_root->data);
	}
}

template <class Entry>
int Binary_tree<Entry>::size() const
{
	return recursive_size(root);
}

template <class Entry>
int Binary_tree<Entry>::recursive_size(Binary_node<Entry> *sub_root) const
{
	if(sub_root == NULL) return 0;
	return 1 + recursive_size(sub_root->left) + recursive_size(sub_root->right);
}

template <class Entry>
int Binary_tree<Entry>::height() const
{
	return recursive_height(root);
}

template <class Entry>
int Binary_tree<Entry>::recursive_height(Binary_node<Entry> *sub_root) const
{
	if(sub_root == NULL) return 0;
	int l_h, r_h;
	l_h = recursive_height(sub_root->left);
	r_h = recursive_height(sub_root->right);
	if(l_h >= r_h) return l_h + 1;
	else return r_h + 1;
}

template <class Entry>
void Binary_tree<Entry>::insert(const Entry &x)
{
	recursive_insert(root, x);
}

template <class Entry>
void Binary_tree<Entry>::recursive_insert(Binary_node<Entry> *sub_root, const Entry &x)
{
	if(sub_root == NULL)
		sub_root = new Binary_node<Entry>(x);
	if(height(sub_root->left) <= height(sub_root->right))
		recursive_insert(sub_root->left, x);
	else recursive_insert(sub_root->right, x);
}

template <class Entry>
void Binary_tree<Entry>::recursive_clear(Binary_node<Entry> *&sub_root)
{
	Binary_node<Entry> *temp = sub_root;
	if(sub_root == NULL) return;
	recursive_clear(sub_root->left);
	recursive_clear(sub_root->right);
	sub_root = NULL;
	delete temp;
}

template <class Entry>
void Binary_tree<Entry>::clear()
{
	recursive_clear(root);
}

template <class Entry>
Binary_tree<Entry>::~Binary_tree()
{
	clear();
}

template <class Entry>
Binary_node<Entry> *Binary_tree<Entry>::recursive_copy(
							Binary_node<Entry> *sub_root)
{
	if(sub_root == NULL) return NULL;
	Binary_node<Entry>* temp = new Binary_node<Entry>(sub_root->data);
	temp->left = recursive_copy(sub_root->left);
	temp->right = recursive_copy(sub_root->right);
	return temp;
}

template <class Entry>
Binary_tree<Entry>::Binary_tree(const Binary_tree<Entry> &original)
{
	root = recursive_copy(original.root);
}

template <class Entry>
Binary_tree<Entry> &Binary_tree<Entry>::operator=
						(const Binary_tree<Entry> &original)
{
	Binary_tree<Entry> new_copy(original);
	clear();
	root = new_copy.root;
	new_copy.root = NULL;
	return *this;
}

template <class Entry>
void Binary_tree<Entry>::level_traverse(void (*visit)(Entry &))
{
	Binary_node<Entry>* sub_root;
	if(root != NULL){
		Queue<Binary_node<Entry> *> waiting_nodes;
		waiting_nodes.append(root);
		do{
			waiting_nodes.retrieve(sub_root);
			(*visit)(sub_root->data);
			if(sub_root->left) waiting_nodes.append(sub_root->left);
			if(sub_root->right) waiting_nodes.append(sub_root->right);
			waiting_nodes.serve();
		}while(!waiting_nodes.empty());
	}
}