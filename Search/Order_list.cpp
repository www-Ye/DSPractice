Error_code Order_list::insert(const Record &data){
	int s = size();
	int position;
	for(position = 0; position < s; position++){
		Record list_data;
		retrieve(position, list_data);
		if(data <= list_data) break;
	}
	return List<Record>::insert(position, data);
}

Error_code Order_list::insert(int position, const Record &data){
	Record list_data;
	if(position > 0){
		retrieve(position - 1, list_data);
		if(data < list_data)
			return fail;
	}
	if(position < size()){
		retrieve(position, list_data);
		if(data > list_data)
			return fail;
	}
	return List<Record>::insert(position, data);
}