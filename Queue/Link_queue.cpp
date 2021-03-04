Queue::Queue(){
	front = rear = NULL;
}

Error_code Queue::append(const Queue_entry &item){
	Node* new_rear = new Node(item);
	if(new_rear == NULL) return overflow;
	if(rear == NULL) front = rear = new_rear;
	else{
		rear->next = new_rear;
		rear = new_rear;
	}
	return success;
}

Error_code Queue::serve(){
	if(front == NULL) return underflow;
	Node* old_front = front;
	front = old_front->next;
	if(front == NULL) rear = NULL;
	delete old_front;
	return success;
}

bool Queue::empty() const{
	return (front == NULL);
}

Error_code Queue::retrieve(Queue_entry &item) const{
	if(front == NULL) return underflow;
	item = front->entry;
	return success;
}

Queue::~Queue{
	while(!empty())
		serve();
}

/*
Queue::Queue(const Queue &original){
	Node* original_node = original.front;
	if(original_node == NULL) front = rear = NULL;
	else{
		front = rear = new Node(original_node.entry);
		while(original_node->next != NULL){
			original_node = original_node->next;
			rear->next = new Node(original_node->entry);
			rear = rear->next;
		}
	}
}

void Queue::operator=(const Queue &original){
	Node *new_front, *new_rear, *original_node = original.front;
	if(original_node == NULL) new_front = new_rear = NULL;
	else{
		new_front = new_rear = new Node(original_node->entry);
		while(original_node->next != NULL){
			original_node = original_node->next;
			new_rear->next = new Node(original_node->entry);
			new_rear = new_rear->next;
		}
	}
	while(!empty())
		serve();
	front = new_front;
	rear = new_rear;
}
*/

Queue::Queue(const Queue &original){
	Node* original_node = original.front;
	front = rear = NULL;
	while(original_node != NULL){
		append(original_node->entry)
		original_node = original_node->next;
	}
}

void Queue::operator=(const Queue &original){
	while(!empty())
		serve();
	Node* original_node = original.front;
	while(original_node != NULL){
		append(original_node->entry)
		original_node = original_node->next;
	}
}