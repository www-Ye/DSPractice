template <class Record>
void Sort_list<Record>::insertion_sort()
{
	int first_unsorted;
	int position;
	Record current;
	for(first_unsorted = 1; first_unsorted < count; first_unsorted++){
		if(entry[first_unsorted] < entry[first_unsorted - 1]){
			position = first_unsorted;
			current = entry[first_unsorted];
			do{
				entry[position] = entry[position - 1];
				position--;
			}while(position > 0 && entry[position - 1] > current);
			entry[position] = current;
		}
	}
}

template <class Record>
void Sort_list<Record>::insertion_sort()
{
	Node<Record>* first_unsorted,
				* last_sorted;
				* current,
				* trailing;
	if(head != NULL){
		last_sorted = head;
		while(last_sorted->next != NULL){
			first_unsorted = last_sorted->next;
			if(first_unsorted->entry < head->entry){
				last_sorted->next = first_unsorted->next;
				first_unsorted->next = head;
				head = first_unsorted;
			}else{
				trailing = head;
				current = trailing->next;
				while(first_unsorted->entry > current->entry){
					trailing = current;
					current = trailing->next;
				}
				if(first_unsorted == current)
					last_sorted = first_unsorted;
				else{
					last_sorted->next = first_unsorted->next;
					first_unsorted->next = current;
					trailing->next = first_unsorted;
				}
			}
		}
	}
}