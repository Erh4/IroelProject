#ifndef OBJECTCLASS_H
#define OBJECTCLASS_H
#include <iostream>
#include <SDL3/SDL.h>
#include <string>
#include "ComponentsClass.h"


/// <summary>
/// Define the default class for all objects
/// Contains a transform component
/// </summary>
class ObjectClass {
private:
	std::string name;			//The name of the object
	std::string tag;			//The tag of the object
	Transform transform;		//World data about the object

public:

	/// <summary>
	/// Constructor of the Object Class.
	/// Set a default Transform object.
	/// </summary>
	/// <param name="name"></param>
	/// <param name="tag"></param>
	ObjectClass(const std::string& name = "Object", const std::string& tag = "Untagged");

	/// <summary>
	/// Return the name of an Object.
	/// </summary>
	/// <returns>The current object's name.</returns>
	std::string GetName() const;

	/// <summary>
	/// Set the name of an Object.
	/// </summary>
	/// <param name="newName"></param>
	void SetName(const std::string& newName);

	/// <summary>
	/// Return the tag of an Object.
	/// </summary>
	/// <returns>The current object's tag.</returns>
	std::string GetTag() const;

	/// <summary>
	/// Set the tag of an object.
	/// </summary>
	/// <param name="newTag"></param>
	void SetTag(const std::string& newTag);

	/// <summary>
	/// Return the transform component of the object.
	/// </summary>
	/// <returns>The current object's transform component.</returns>
	Transform& GetTransform();
};

#endif // !OBJECTCLASS_H
