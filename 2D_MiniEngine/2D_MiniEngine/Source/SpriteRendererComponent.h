#pragma once

#include <./SFML/Graphics.hpp>
#include "Component.h"

class SpriteRendererComponent : public Component
{
public:
	SpriteRendererComponent() { renderTarget = new sf::RenderWindow(); }
	SpriteRendererComponent(sf::RenderTarget* inWindow) { renderTarget = inWindow; }
	virtual ~SpriteRendererComponent() { }
	virtual void Update();

	void SetTexture(const char* imageURL);
	void SetPosition(float x, float y);
	void SetOrientation(float inOrientation);
	void SetScale(float x, float y);

private:
	sf::RenderTarget* renderTarget;
	sf::Texture texture;
	sf::Sprite sprite;
};