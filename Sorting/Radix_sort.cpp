const int max_chars = 28;
template <class Record>
void Sortable_list<Record>::radix_sort
{
	Record data;
	Queue queues[max_chars];
	for(int position = key_size - 1; position >= 0; position--){
		while(remove(0, data) == success){
			int queue_number = alphabetic_order(data.key_letter(position));
			queue[queue_number].append(data);
		}
	rethread(queues);
	}
}

int alphabetic_order(char c)
{
	if(c == ' ') return 0;
	if('a' <= c && c <= 'z') return c - 'a' + 1;
	if('A' <= c && c <= 'Z') return c - 'A' + 1;
	return 27;
}

template <class Record>
void Sortable_list<Record>::rethread(Queue queues[])
{
	Record data;
	for(int i = 0; i < max_chars; i++){
		while(!queue[i].empty()){
			queue[i].retrieve(data);
			insert(size(), data);
			queues[i].serve();
		}
	}
}