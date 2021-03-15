#include "List.h"

template <class List_entry>
Node<List_entry>* List<List_entry>::set_position(int position) const{
	Node<List_entry>* q = head;
	for(int i = 0; i < position; i++) q = q->next;
	return q;
}

template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x){
	if(position < 0 || position > count)
		return new_range_error;
	Node<List_entry>* new_node, *previous, *following;
	if(position > 0){
		previous = set_position(position - 1);
		following = previous->next;
	}
	else following = head;
	new_node = new Node<List_entry> (x, following);
	if(new_node == nullptr)
		return overflow;
	if(position == 0)
		head = new_node;
	else
		previous->next = new_node;
	count++;
	return success;
}

template <class List_entry>
List<List_entry>::List(){
	count = 0;
	head = nullptr;
}

template <class List_entry>
List<List_entry>::List(const List<List_entry> &copy){
	count = copy.count;
	Node<List_entry> *new_node, *old_node = copy.head;
	if(old_node == nullptr) head = nullptr;
	else{
		new_node = head = new Node<List_entry>(old_node->entry);
		while(old_node->next != nullptr){
			old_node = old_node->next;
			new_node->next = new Node<List_entry>(old_node->entry);
			new_node = new_node->next;
		}
	}
}

template <class List_entry>
void List<List_entry>::operator = (const List<List_entry> &copy){
	List new_copy(copy);
	clear();
	count = new_copy.count;
	head = new_copy.head;
	new_copy.count = 0;
	new_copy.head = nullptr;
}

template <class List_entry>
List<List_entry>::~List(){
	clear();
}

template <class List_entry>
void List<List_entry>::clear(){
	Node<List_entry> *p, *q;
	for(p = head; p; p = q){
		q = p->next;
		delete p;
	}
	count = 0;
	head = nullptr;
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
	Node<List_entry>* current;
	if(position < 0 || position >= count) return new_range_error;
	current = set_position(position);
	current->entry = x;
	return success;
}

template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const{
	Node<List_entry>* current;
	if(position < 0 || position >= count) return new_range_error;
	current = set_position(position);
	x = current->entry;
	return success;
}

template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x){
	Node<List_entry> *prior, *current;
	if(count == 0) return fail;
	if(position < 0 || position >= count) return new_range_error;
	if(position > 0){
		prior = set_position(position - 1);
		current = prior->next;
		prior->next = current->next;
	}else{
		current = head;
		head = head->next;
	}
	x = current->entry;
	delete current;
	count--;
	return success;
}

template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &)){
	Node<List_entry>* q;
	for(q = head; q; q = q->next)
		(*visit)(q->entry);
}