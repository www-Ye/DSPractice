template <class List_entry>
void List<List_entry>::set_position(int position) const{
	if(position < current_position){
		current_position = 0;
		current = head;
	}
	for(; current_position != position; current_position++)
		current = current->next;
}

template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x){
	Node<List_entry>* old_node;
	if(count == 0) return fail;
	if(position < 0 || position >= count) return range_error;
	if(position > 0){
		set_position(position - 1);
		old_node = current->next;
		current->next = old_node->next;
	}else{
		old_node = head;
		current = head = old_node->next;
		current_position = 0;
	}
	x = old_node->entry;
	delete old_node;
	count--;
	return success;
}