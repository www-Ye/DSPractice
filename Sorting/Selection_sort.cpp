template <class Record>
void Sortable_list<Record>::Selection_sort()
{
	for(int position = count - 1; position > 0; position--){
		int max = max_key(0, position);
		swap(max, position);
	}
}

template <class Record>
int Sortable_list<Record>::max_key(int low, int high)
{
	int largest, current;
	largest = low;
	for(current = low + 1; current <= high; current++)
		if(entry[largest] < entry[current])
			largest = current;
	return largest;
}

template <class Record>
void Sortable_list<Record>::swap(int low, int high)
{
	Record temp;
	temp = entry[low];
	entry[low] = entry[high];
	entry[high] = temp;
}