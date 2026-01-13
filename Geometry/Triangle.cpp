#include "Triangle.h"

Triangle::Triangle() {
	this->edge1 = nullptr;
	this->edge2 = nullptr;
	this->edge3 = nullptr;
}

Triangle::Triangle(Edge* edge1, Edge* edge2, Edge* edge3)
{
	this->edge1 = edge1;
	this->edge2 = edge2;
	this->edge3 = edge3;
}

Triangle::~Triangle() {};

void Triangle::RenderTriangle(SDL_Renderer* renderer) {
	SDL_RenderLine(renderer, this->edge1->vertice1->x, this->edge1->vertice1->y, this->edge1->vertice2->x, this->edge1->vertice2->y);
	SDL_RenderLine(renderer, this->edge2->vertice1->x, this->edge2->vertice1->y, this->edge2->vertice2->x, this->edge2->vertice2->y);
	SDL_RenderLine(renderer, this->edge3->vertice1->x, this->edge3->vertice1->y, this->edge3->vertice2->x, this->edge3->vertice2->y);
}