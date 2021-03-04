template <class Weight, int graph_size>
class Network: public Digraph<Weight, graph_size>{
public:
	Network();
	void read();
	void make_empty(int size = 0);
	void add_edge(Vertex v, Vertex w, Weight x);
	void minimal_spanning(Vertex source,
						  Network<Weight, graph_size> &tree) const;
}