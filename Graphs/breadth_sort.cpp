template <int graph_size>
void Digraph<graph_size>::breadth_sort(List<Vertex> &topological_order)
{
	topological_order.clear();
	Vertex v, w;
	int predecessor_count[graph_size];
	for(v = 0; v < count; v++) predecessor_count[v] = 0;
	for(v = 0; v < count; v++)
		for(int i = 0; i < neighbors[v].size(); i++){
			neighbors[v].retrieve(i, w);
			predecessor_count[w]++;
		}
	Queue ready_to_process;
	for(v = 0; v < count; v++)
		if(predecessor_count[v] == 0)
			ready_to_process.append(v);
	while(!ready_to_process.empty()){
		ready_to_process.retrieve(v);
		topological_order.insert(topological_order.size(), v);
		for(int j = 0; j < neighbors[v].size(); j++){
			neighbors[v].retrieve(j, w);
			predecessor_count[w]--;
			if(predecessor_count[w] == 0)
				ready_to_process.append(w);
		}
		ready_to_process.serve();
	}
}