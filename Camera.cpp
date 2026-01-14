#include "Camera.h"

Camera::Camera() {
	this->position = Coordinate(0, 0, 0);
}

Camera::Camera(float x, float y, float z, float focalLength) {
	this->position = Coordinate(x, y, z);
	this->focalLength = focalLength;
}

Camera::~Camera() {

}

