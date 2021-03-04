template <int max_set>
struct Set{
	bool is_element[max_set];
};

template <int max_size>
class Digraph{
	int count;
	Set<max_size> neighbors[max_size];
};

template <int max_size>
class Digraph{
	int count;
	bool adjacency[max_size][max_size];
};

typedef int Vertex;

template <int graph_size>
class Digraph{
public:
	Digraph();
	void read();
	void write();
	void depth_sort(List<Vertex> &topological_order);
	void breadth_sort(List<Vertex> &topological_order);
private:
	int count;
	List<Vertex> neighbors[graph_size];
	void recursive_depth_sort(Vertex v, bool visit[],
							  List<Vertex> &topological_order);
};

class Edge;
class Vertex{
	Edge* first_edge;
	Vertex* next_vertex;
};
class Edge{
	Vertex* end_vertex;
	Edge* next_edge;
};
class Digraph{
	Vertex* first_vertex;
};