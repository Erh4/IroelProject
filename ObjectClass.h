#ifndef OBJECTCLASS_H
#define OBJECTCLASS_H
#include <iostream>
#include <SDL3/SDL.h>
#include <string>
#include <vector>
#include "ComponentsClass.h"
#include <memory>

class Component;


/// <summary>
/// Define the default class for all objects
/// Contains a transform component
/// </summary>
class ObjectClass {
private:
	std::string name;			//The name of the object
	std::string tag;			//The tag of the object
	std::vector<std::unique_ptr<Component>> components;

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
	/// Add a generic type component to a smart pointer
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns>The pointer to the current component</returns>
	template<typename T> T* AddComponent() {
		auto comp = std::make_unique<T>(this);
		T* ptr = comp.get();
		components.push_back(std::move(comp));
		return ptr;
	}


	/// <summary>
	/// Search for a specific component in the components list
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns>The pointer to the wanted component</returns>
	template<typename T> T* GetComponent() {
		for (auto& comp : components) {
			T* result = dynamic_cast<T*>(comp.get());
			if (result != nullptr)
				return result;
		}
		return nullptr;
	}


	/// <summary>
	/// Search for a specific component in the components list and deletes it
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns>A boolean stating the result. True if deleted and False otherwise.</returns>
	template<typename T> bool RemoveComponent() {
		for (auto it = components.begin(); it != components.end(); ++it) {
			if (dynamic_cast<T*>(it->get()) != nullptr) {
				components.erase.(it);
				return true;
			}
		}
		return false;
	}

};

#endif // !OBJECTCLASS_H
