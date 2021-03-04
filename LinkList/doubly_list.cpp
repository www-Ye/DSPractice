template <class List_entry>
Node<List_entry>::Node(){
	next = back = NULL;
}

template <class List_entry>
Node<List_entry>::Node(List_entry data, Node<Node_entry>* link_back = NULL,
										Node<Node_entry>* link_next = NULL)
{
	entry = data;
	back = link_back;
	next = link_next;
}

template <class List_entry>
void List<List_entry>::set_position(int position) const{
	if(current_position <= position)
		for(; current_position != position; current_position++)
			current = current->next;
	else
		for(; current_position != position; current_position--)
			current = current->back;
}

template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x){
	Node<List_entry>* new_node, *following, *preceding;
	if(position < 0 || position > count) return range_error;
	if(position == 0){
		if(count == 0) following = NULL;
		else{
			set_position(0);
			following = current;
		}
		preceding = NULL;
	}
	else{
		set_position(position - 1);
		preceding = current;
		following = preceding->next;
	}
	new_node = new Node<List_entry>(x, preceding, following);
	if(new_node == NULL) return overflow;
	if(preceding != NULL) preceding->next = new_node;
	if(following !- NULL) following->back = new_node;
	current = new_node;
	current_position = position;
	count++;
	return success;
}

template <class List_entry>
List<List_entry>::List(){
	count = 0;
	current = NULL;
	current_position = -1;
}

template <class List_entry>
List<List_entry>::List(const List<List_entry> &copy){
	count = copy.count;
	current_position = copy.current_position;
	Node<List_entry> *new_node, *old_node = copy.current;
	if(old_node == NULL) current = NULL;
	else{
		new_node = current = new Node<List_entry>(old_node->entry);
		while(old_node->next != NULL){
			old_node = old_node->next;
			new_node->next = new Node<List_entry>(old_node->entry, new_node);
			new_node = new_node->next;
		}
		old_node = copy.current;
		new_node = current;
		while(old_node->back != NULL){
			old_node = old_node->back;
			new_node->back = new Node<List_entry>(old_node->entry, NULL, new_node);
			new_node = new_node->back;
		}
	}
}

template <class List_entry>
void List<List_entry>::operator = (const List<List_entry> &copy){
	List new_copy(copy);
	clear();
	count = new_copy.count;
	current_position = new_copy.current_position;
	current = new_copy.current;
	new_copy.count = 0;
	new_copy.current_position = -1;
	new_copy.current = NULL;
}

template <class List_entry>
List<List_entry>::~List(){
	clear();
}

template <class List_entry>
void List<List_entry>::clear(){
	Node<List_entry> *p, *q;
	if(current == NULL) return;
	for(p = current->back; p; p = q){
		q = p->back;
		delete p;
	}
	for(p = current; p; p = q){
		q = p->next;
		delete p;
	}
	count = 0;
	current_position = -1;
	current = NULL;
}

template <class List_entry>
int List<List_entry>::size() const{
	return count;
}

template <class List_entry>
bool List<List_entry>::empty() const{
	return count <= 0;
}

template <class List_entry>
bool List<List_entry>::full() const{
	return false;
}

template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x){
	if(position < 0 || position >= count) return range_error;
	set_position(position);
	current->entry = x;
	return success;
}

template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const{
	if(position < 0 || position >= count) return range_error;
	set_position(position);
	x = current->entry;
	return success;
}

template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x){
	Node<List_entry> *old_node, *neighbour;
	if(count == 0) return fail;
	if(position < 0 || position >= count) return range_error;
	set_position(position)
	old_node = current;
	if(neighbour = old_node->back) neighbour->next = old_node->next;
	if(neighbour = old_node->next){
		neighbour->back = old_node->back;
		current = neighbour;
	}else{
		current = current->back;
		current_position--;
	}
	x = old_node->entry;
	delete old_node;
	count--;
	return success;
}

template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &)){
	Node<List_entry>* to_visit = current;
	if(to_visit != NULL)
		for(; to_visit->back; to_visit = to_visit->back)
			;
	for(; to_visit; to_visit = to_visit->next)
		(*visit)(to_visit->entry);
}