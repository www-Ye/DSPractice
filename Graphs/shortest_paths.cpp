template <class Weight, int graph_size>
void Digraph<Weight, graph_size>::set_distances(Vertex source,
								  Weight distance[]) const
{
	Vertex v, w;
	bool found[graph_size];
	for(v = 0; v < count; v++){
		found[v] = false;
		distance[v] = adjacency[source][v];
	}
	found[source] = true;
	distance[source] = 0;
	for(int i = 0; i < count; i++){
		Weight min = infinity;
		for(w = 0; w < count; w++) if(!fount[w])
			if(distance[w] < min){
				v = w;
				min = distance[w];
			}
		found[v] = true;
		for(w = 0; w < count; w++) if(!found[w])
			if(min + adjacency[v][w] < distance[w])
				distance[w] = min + adjacency[v][w];
	}
}