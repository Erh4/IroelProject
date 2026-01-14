#ifndef COORDINATE_INCLUDE
#define COORDINATE_INCLUDE

#include <iostream>
#include <vector>


class Coordinate {

public:
	Coordinate();
	Coordinate(float x, float y, float z);
	~Coordinate();

	float x;
	float y;
	float z;

	void UpdateCoordinatePosition(float x, float y, float z);

	void addNormalToCoordinate(std::vector<float> normal);

	void addToPosition(std::vector<float> vec);

	std::vector<float> getVector();
};



#endif // !COORDINATE_INCLUDE
