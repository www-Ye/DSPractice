template <class Record>
class Search_tree :public Binary_tree<Record>{
public:
	Error_code insert(const Record &new_data);
	Error_code remove(const Record &old_data);
	Error_code tree_search(Record &target) const;
private:
};