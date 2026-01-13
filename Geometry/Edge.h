#ifndef EDGE_INCLUDE
#define EDGE_INCLUDE


#include "Coordinate.h"

class Edge {
public :
	Edge();
	Edge(Coordinate* vertice1, Coordinate* vertice2);
	~Edge();

	Coordinate* vertice1;
	Coordinate* vertice2;

};
#endif // !EDGE_INCLUDE
