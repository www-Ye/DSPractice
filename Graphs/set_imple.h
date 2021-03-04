template <int max_set>
struct Set{
	bool is_element[max_set];
};

template <int max_size>
class Digraph{
	int count;
	Set<max_size> neighbors[max_size];
};