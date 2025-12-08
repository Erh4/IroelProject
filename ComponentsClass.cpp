#include "ComponentsClass.h"


void Component::Start() {};
void Component::Update() {};
void Component::OnDestroy() {};


TransformComponent::TransformComponent(ObjectClass* owner)
	: Component(owner) {
	x = 0;
	y = 0;
	z = 0;
	width = 0;
	height = 0;
	rotX = 0;
	rotY = 0;
	rotZ = 0;
}

