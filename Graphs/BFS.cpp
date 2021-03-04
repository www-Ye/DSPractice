template <int max_size>
void Digraph<max_size>::breadth_first(void (*visit)(Vertex &)) const
/*Post: The function *visit has been performed at each vertex of the Digraph in
		breadth-first order.
  Uses: Methods of class Queue. */
{
	Queue q;
	bool visited[max_size];
	Vertex v, w, x;
	for(all v in G) visited[v] = false;
	for(all v in G)
		if(!visited[v]){
			q.append(v);
			while(!q.empty()){
				q.retrieve(w);
				if(!visited[w]){
					visited[w] = true;
					(*visit)(w);
					for(all x adjacent to w)
						q.append(x);
				}
				q.serve();
			}
		}
}