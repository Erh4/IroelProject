#ifndef COORDINATE_INCLUDE
#define COORDINATE_INCLUDE

#include <iostream>

class Coordinate {

public:
	Coordinate();
	Coordinate(float x, float y, float z);
	~Coordinate();

	float x;
	float y;
	float z;

	void UpdateCoordinatePosition(float x, float y, float z);
};



#endif // !COORDINATE_INCLUDE
