template <class Weight, int graph_size>
void Network<Weight, graph_size>::minimal_spanning(Vertex source,
					Network<Weight, graph_size> &tree) const
{
	tree.make_empty(count);
	bool component[graph_size];
	Weight distance[graph_size];
	Vertex neighbor[graph_size];
	Vertex w;
	for(w = 0; w < count; w++){
		component[w] = false;
		distance[w] = adjacency[source][w];
		neighbor[w] = source;
	}
	component[source] = true;
	for(int i = 1; i < count; i++){
		Vertex v;
		Weight min = infinity;
		for(w = 0; w < count; w++) if(!component[w])
			if(distance[w] < min){
				v = w;
				min = distance[w];
			}
		if(min < infinity){
			component[v] = true;
			tree.add_edge(v, neighbor[v], distance[v]);
			for(w = 0; w < count; w++) if(!component[w])
				if(adjacency[v][w] < distance[w]){
					distance[w] = adjacency[v][w];
					neighbor[w] = v;
				}
		}
		else break;
	}
}