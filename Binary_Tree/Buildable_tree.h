template <class Record>
class Buildable_tree :public Search_tree<Record>{
public:
	Error_code build_tree(const List<Record> &supply);
private:
};