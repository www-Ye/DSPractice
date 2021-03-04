template <int max_size>
void Digraph<max_size>::depth_first(void (*visit)(Vertex &)) const
/*Post: The function *visit has been performed at each vertex of the Digraph in
		depth-first order.
  Uses: Method traverse to produce the recursive depth-first order. */
{
	bool visited[max_size];
	Vertex v;
	for(all v in G) visited[v] = false;
	for(all v in G) if(!visited[v])
		traverse(v, visited, visit);
}

template <int max_size>
void Digraph<max_size>::traverse(Vertex &v, bool visit[],
								 void (*visit)(Vertex &)) const
/*Pre:  v is a vertex of the Digraph.
  Post: The depth-first traversal, using function *visit, has been completed for v
		and for all vertices that can be reached from v.
  Uses: traverse recursively. */
{
	Vertex w;
	visited[v] = true;
	(*visit)(v);
	for(all w adjacent to v)
		if(!visited[w])
			traverse(w, visited, visit);
}