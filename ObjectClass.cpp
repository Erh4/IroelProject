#include "ObjectClass.h"



ObjectClass::ObjectClass(const std::string& name, const std::string& tag)
	:name(name), tag(tag) {
	this->transform = Transform();
}

std::string ObjectClass::GetName() const {
	return this->name;
}

void ObjectClass::SetName(const std::string& newName) {
	this->name = newName;
}

std::string ObjectClass::GetTag() const {
	return this->tag;
}

void ObjectClass::SetTag(const std::string& newTag) {
	this->tag = newTag;
}

Transform& ObjectClass::GetTransform() {
	return this->transform;
}