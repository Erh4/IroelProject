#ifndef COMPONENTSCLASS_H
#define COMPONENTSCLASS_H

/// <summary>
/// Transform component for world data of the object 
/// position, size and rotation
/// </summary>
class Transform {

public:
	/// <summary>
	/// Constructor of Tranfsform class
	/// Set all variables to 0 (maybe later the spawnpoint of the world)
	/// </summary>
	Transform();
	float x, y, z, width, height, rotX, rotY, rotZ;
};
#endif