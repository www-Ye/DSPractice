template <class Record>
void Sortable_list<Record>::quick_sort()
{
	recursive_quick_sort(0, count - 1);
}

template <class Record>
void Sortable_list<Record>::recursive_quick_sort(int low, int high)
{
	int pivot_position;
	if(low < high){
		pivot_position = partition(low, high);
		recursive_quick_sort(low, pivot_position - 1);
		recursive_quick_sort(pivot_position + 1, high);
	}
}

template <class Record>
int Sortable_list<Record>::partition(int low, int high)
{
	Record pivot;
	int i, last_small;
	swap(low, (low + high) / 2);
	pivot = entry[low];
	last_small = low;
	for(i = low + 1; i <= high; i++){
		if(entry[i] < pivot){
			last_small = last_small + 1;
			swap(last_small, i);
		}
	}
	swap(low, last_small);
	return last_small;
}