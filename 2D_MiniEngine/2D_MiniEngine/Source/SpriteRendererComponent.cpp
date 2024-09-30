#include "SpriteRendererComponent.h"

void SpriteRendererComponent::Update()
{
	if (renderTarget != nullptr)
	{
		renderTarget->draw(sprite);
	}
}

void SpriteRendererComponent::SetTexture(const char* imageURL)
{
	if (!texture.loadFromFile(imageURL))
	{
		return;
	}
	
	sprite.setTexture(texture);
}

void SpriteRendererComponent::SetPosition(float x, float y)
{
	sprite.setPosition(sf::Vector2f(x, y));
}

void SpriteRendererComponent::SetOrientation(float inOrientation)
{
	sprite.setRotation(inOrientation);
}

void SpriteRendererComponent::SetScale(float x, float y)
{
	sprite.setScale(sf::Vector2f(x, y));
}