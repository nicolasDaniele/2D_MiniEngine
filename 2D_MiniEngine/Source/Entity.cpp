#include "Entity.h"
#include "Component.h"

void Entity::Update()
{
	for (Component* component : components) 
	{
		component->Update();
	}
}

void Entity::AddComponent(Component* inComponent)
{
	if (inComponent != nullptr)
	{
		components.push_back(inComponent);
	}
}