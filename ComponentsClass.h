#ifndef COMPONENTSCLASS_H
#define COMPONENTSCLASS_H

class ObjectClass;


/// <summary>
/// Generic component for an object
/// </summary>
class Component {
public:
	Component(ObjectClass* owner) : owner(owner) {};
	virtual ~Component() = default;
	virtual void Start();
	virtual void Update();
	virtual void OnDestroy();

protected:
	ObjectClass* owner;
};



/// <summary>
/// Transform component for world data of the object 
/// position, size and rotation
/// </summary>
class TransformComponent : public Component {
public :
	/// <summary>
	/// Constructor of Tranfsform class
	/// Set all variables to 0 (maybe later the spawnpoint of the world)
	/// </summary>
	TransformComponent(ObjectClass* owner);
	float x, y, z;
	float width, height;
	float rotX, rotY, rotZ;
};
#endif