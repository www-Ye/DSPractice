Double_stack::Double_stack(){
	count_a = 0;
	count_b = maxstack - 1;
}

bool Double_stack::empty_a() const{
	return count_a <= 0;
}

bool Double_stack::empty_b() const{
	return count_b >= maxstack - 1;
}

Error_code Double_stack::top_a(Stack_entry &item) const{
	if(empty_a())
		return underflow;
	item = entry[count_a - 1];
	return success;
}

Error_code Double_stack::top_b(Stack_entry &item) const{
	if(empty_b())
		return underflow;
	item = entry[count_b + 1];
	return success;
}

Error_code Double_stack::pop_a(){
	if(empty_a())
		return underflow;
	count_a--;
	return success;
}

Error_code Double_stack::pop_b(){
	if(empty_b())
		return underflow;
	count_b++;
	return success;
}

Error_code Double_stack::push_a(const Stack_entry &item){
	if(count_a - count_b == 1)
		return overflow;
	entry[count_a++] = item;
	return success;
}

Error_code Double_stack::push_a(const Stack_entry &item){
	if(count_a - count_b == 1)
		return overflow;
	entry[count_b--] = item;
	return success;
}