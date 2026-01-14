#ifndef CAMERA_INCLUDE
#define CAMERA_INCLUDE

#include "Geometry/Coordinate.h"

class Camera {
public :
	Camera();
	Camera(float x, float y, float z, float focalLength);
	~Camera();
	Coordinate position;
	float focalLength;
};
#endif