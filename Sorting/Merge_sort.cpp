template <class Record>
void Sortable_list<Record>::merge_sort()
{
	recursive_merge_sort(head);
}

template <class Record>
void Sortable_list<Record>::recursive_merge_sort(Node<Record>* &sub_list)
{
	if(sub_list != NULL && sub_list->next != NULL){
		Node<Record>* second_half = divide_from(sub_list);
		recursive_merge_sort(sub_list);
		recursive_merge_sort(second_half);
		sub_list = merge(sub_list, second_half);
	}
}

template <class Record>
Node<Record>* Sortable_list<Record>::divide_from(Node<Record>* sub_list)
{
	Node<Record>* position,
				* midpoint,
				* second_half;
	if((midpoint = sub_list) == NULL) return NULL;		// List is empty
	position = midpoint->next;
	while(position != NULL){
		position = position->next;		// Move position twice for midpoint's one move
		if(position != NULL){
			midpoint = midpoint->next;
			position = position->next;
		}
	}
	second_half = midpoint->next;
	midpoint->next = NULL;
	return second_half;
}

template <class Record>
Node<Record>* Sortable_list<Record>::merge(Node<Record>* first, 
										   Node<Record>* second)
{
	Node<Record>* last_sorted;
	Node<Record> combined;
	last_sorted = &combined;
	while(first != NULL && second != NULL){
		if(first->entry <= second->entry){
			last_sorted->next = first;
			last_sorted = first;
			first = first->next;
		}
		else{
			last_sorted->next = second;
			last_sorted = second;
			second = second->next;
		}
	}
	if(first == NULL)
		last_sorted->next = second;
	else
		last_sorted->next = first;
	return combined.next;
}
}