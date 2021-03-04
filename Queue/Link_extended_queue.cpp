int Extended_queue::size() const{
	Node* window = front;
	int count = 0;
	while(window != NULL){
		window = window->next;
		count++;
	}
	return count;
}

bool Extended_queue::full() const{
	return false;
}

void Extended_queue::clear(){
	while(!empty())
		serve();
}

Error_code Extended_queue::serve_and_retireve(Queue_entry &item){
	if(front == NULL) return underflow;
	retrieve(item);
	serve();
	return success;
}