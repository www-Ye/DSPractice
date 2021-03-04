template <int graph_size>
void Digraph<graph_size>::depth_sort(List<Vertex> &topological_order)
{
	bool visited[graph_size];
	Vertex v;
	for(v = 0; v < count; v++) visited[v] = false;
	topological_order.clear();
	for(v = 0; v < count; v++)
		if(!visited[v])
			recursive_depth_sort(v, visited, topological_order);
}

template <int graph_size>
void Digraph<graph_size>::recursive_depth_sort(Vertex v, bool *visited,
							List<Vertex> &topological_order)
{
	visited[v] = true;
	int degree = neighbors[v].size();
	for(int i = 0; i < degree; i++){
		Vertex w;
		neighbors[v].retrieve(i, w);
		if(!visited[w])
			recursive_depth_sort(w, visited, topological_order);
	}
	topological_order.insert(0, v);
}