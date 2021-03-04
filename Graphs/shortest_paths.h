template <class Weight, int graph_size>
class Digraph{
public:
	void set_distances(Vertex source, Weight distance[]) const;
protected:
	int count;
	Weight adjacency[graph_size][graph_size];
};