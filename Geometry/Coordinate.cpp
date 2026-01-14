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

void Coordinate::addNormalToCoordinate(std::vector<float> normal) {
	this->x += normal.at(0);
	this->y += normal.at(1);
	this->z += normal.at(2);
	
}


std::vector<float> Coordinate::getVector() {
	return { this->x, this->y, this->z };
}

void Coordinate::addToPosition(std::vector<float> vec) {
	this->x += vec.at(0);
	this->y += vec.at(1);
	this->z += vec.at(2);
}
Coordinate::~Coordinate() {};

