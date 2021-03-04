class Edge;     // forward declaration
class Vertex{
	Edge *first_edge;
	Vertex *next_vertex;
};
class Edge{
	Vertex *end_point;
	Edge *next_edge;
};
class Digraph{
	Vertex *first_vertex;
};