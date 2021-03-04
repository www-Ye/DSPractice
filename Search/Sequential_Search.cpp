Error_code sequential_search(const List<Record> &the_list, 
							const Key &target, int &position){
	int s = the_list.size();
	for(position = 0; position < s; position++){
		Record data;
		the_list.retrieve(position, data);
		if(data == target) return success;
	}
	return not_present;
}