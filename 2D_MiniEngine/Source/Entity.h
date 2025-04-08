#pragma once

#include "Transform.h"
#include <vector>

class Component;

class Entity
{
public:
	Entity() : transform(Transform()) { }
	virtual ~Entity() { }
	void Update();
	void AddComponent(Component* inComponent);

private:
	Transform transform;
	std::vector<Component*> components;
};