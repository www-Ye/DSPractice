template <class Record>
void Sortable_list<Record>::Shell_sort()
{
	int increment, start;
	increment = count;
	do{
		increment = increment / 3 + 1;
		for(start = 0; start < increment; start++)
			sort_interval(start, increment);
	}while(increment > 1);
}