#include "Coordinate.h"


Coordinate::Coordinate() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}
Coordinate::Coordinate(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Coordinate::UpdateCoordinatePosition(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Coordinate::~Coordinate() {};