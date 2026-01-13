#ifndef TRIANGLE_INCLUDE
#define TRIANGLE_INCLUDE

#include <SDL3/SDL.h>
#include "Edge.h"

class Triangle {
public:
	Triangle();
	Triangle(Edge* edge1, Edge* edge2, Edge* edge3);
	~Triangle();
	void RenderTriangle(SDL_Renderer* renderer);
	Edge* edge1;
	Edge* edge2;
	Edge* edge3;
};

#endif // !TRIANGLE_INCLUDE
