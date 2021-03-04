Error_code Trie::trie_search(const Key &target, Record &x) const
{
	int position = 0;
	char next_char;
	Trie_node* location = root;
	while(location != NULL && (next_char = target.key_letter(position)) != ''){
		location = location->branch[alphabetic_order(next_char)];
		position++;
	}
	if(location != NULL && location->data != NULL){
		x = *(location->data);
		return success;
	}
	else
		return not_present;
}

Error_code Trie::insert(const Record &new_entry)
{
	Error_code result = success;
	if(root == NULL) root = new Trie_node;
	int position = 0;
	char next_char;
	Trie_node* location = root;
	while(location != NULL &&
		 (next_char = new_entry.key_letter(position)) != ''){
		int next_position = alphabetic_order(next_char);
		if(location->branch[next_position] == NULL)
			location->branch[next_position] = new Trie_node;
		location = location->branch[next_position];
		position++;
	}
	if(location->data != NULL) result = duplicate_error;
	else location->data = new Record(new_entry);
	return result;
}