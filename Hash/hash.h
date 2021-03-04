class Key: public String{
public:
	char key_letter(int position) const;
	void make_blank();
};

const int hash_table = 997;
class Hash_table{
public:
	Hash_table();
	void clear();
	Error_code insert(const Record &new_entry);
	Error_code retrieve(const Key &target, Record &found) const;
private:
	Record table[hash_size];
};



const int hash_size = 997;
class Hash_table{
public:
	Hash_table();
	void clear();
	Error_code insert(const Record &new_entry);
	Error_code retrieve(const Key &target, Record &found) const
	Error_code remove(const Key &target, Record &found);
private:
	List<Record> table[hash_table];
};