#include "Edge.h"


Edge::Edge() {
	this->vertice1 = nullptr;
	this->vertice2 = nullptr;
}
Edge::Edge(Coordinate* vertice1, Coordinate* vertice2) {
	this->vertice1 = vertice1;
	this->vertice2 = vertice2;
}

void Edge::RenderEdge(Camera* camera) {
	//SDL_RenderLine((vertice1->x / vertice1->z) * camera->focalLength + camera->position.x, 
	//						(vertice1->y / vertice1->z) * camera->focalLength + camera->position.y,
	//						(vertice2->x / vertice1->z) * camera->focalLength + camera->position.x,
	//						(vertice2->y / vertice1->z) * camera->focalLength + camera->position.y);
}

Edge::~Edge() {
};