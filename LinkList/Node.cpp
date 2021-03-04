template <class List_entry>
Node<List_entry>::Node(){
	next = NULL;
}

template <class List_entry>
Node<List_entry>::Node(List_entry data, Node<List_entry>* link = NULL){
	entry = data;
	next = link;
}
