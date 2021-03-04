int hash(const Key &target)
{
	int value = 0;
	for(int position = 0; position < 8; position++)
		value = 4 * value + target.key_letter(position);
	return value % hash_size;
}

Error_code Hash_table::insert(const Record &new_entry)
{
	Error_code result = success;
	int probe_count,
		increment,
		probe;
	Key null;
	null.make_blank();
	probe = hash(new_entry);
	probe_count = 0;
	increment = 1;
	while(table[probe] != null
		 && table[probe] != new_entry
		 && probe_count < (hash_size + 1) / 2){
		probe_count++;
		probe = (probe + increment) % hash_size;
		increment += 2;
	}
	if(table[probe] == null) table[probe] = new_entry;
	else if(table[probe] == new_entry) result = duplicate_error;
	else result = overflow;
	return result;
}

Error_code Hash_table::retrieve(const Key &target, Record &found) const
{
	int probe_count,
		increment,
		probe;
	Key null;
	null.make_blank();
	probe = hash(targe);
	probe_count = 0;
	increment = 1;
	while(table[probe] != null &&
		 table[probe] != target
		 && probe_count < (hash_size + 1) / 2){
		probe_count++;
		probe = (probe + increment) % hash_size;
		increment += 2;
	}
	if(table[probe] == target){
		found = table[probe];
		return success;
	}
	else return not_present;
}



Hash_table::Hash_table()
{
	
}

Hash_table::clear()
{
	for(int i = 0; i < hash_size; i++)
		table[i].clear();
}

Hash_table::insert(const Record &new_entry)
{
	Record old_copy;
	if(retrieve(new_entry, old_copy) == success)
		return duplicate_error;
	int probe = hash(new_entry);
	return table[probe].insert(0, new_entry);
}

Error_code Hash_table::retrieve(const Key &target, Record &found) const
{
	int position;
	Error_code outcome;
	int probe = hash(target);
	outcome = sequential_search(table[probe], target, position);
	if(outcome == success)
		table[probe].retrieve(position, found);
	return outcome;
}

Error_code Hash_table::remove(const Key &target, Record &found)
{
	int position;
	int probe = hash(target);
	if(sequential_search(table[probe], target, position) != success)
		return not_present;
	return table[probe].remove(position, found);
}

