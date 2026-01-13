#include "Edge.h"


Edge::Edge() {
	this->vertice1 = nullptr;
	this->vertice2 = nullptr;
}
Edge::Edge(Coordinate* vertice1, Coordinate* vertice2) {
	this->vertice1 = vertice1;
	this->vertice2 = vertice2;
}

Edge::~Edge() {};