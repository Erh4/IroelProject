#ifndef EDGE_INCLUDE
#define EDGE_INCLUDE


#include "Coordinate.h"
#include <SDL3/SDL.h>
#include "../Camera.h"


class Edge {
public :
	Edge();
	Edge(Coordinate* vertice1, Coordinate* vertice2);
	~Edge();

	Coordinate* vertice1;
	Coordinate* vertice2;

	void RenderEdge(Camera* camera);

};
#endif // !EDGE_INCLUDE
