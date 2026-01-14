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

Triangle::~Triangle() {
};

void Triangle::RenderTriangle(Camera* camera) {

	edge1->RenderEdge(camera);
	edge2->RenderEdge(camera);
	edge3->RenderEdge(camera);
}

