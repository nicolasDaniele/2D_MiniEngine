#pragma once

#include <SFML/Graphics.hpp>
#include "Component.h"

class SpriteRendererComponent : public Component
{
public:
	SpriteRendererComponent() : renderTarget(new sf::RenderWindow()), sprite(sf::Sprite(texture)) { }
	SpriteRendererComponent(sf::RenderTarget* inWindow, sf::Texture inTexture) : renderTarget(inWindow), texture(inTexture), sprite(sf::Sprite(texture)) { }

	virtual ~SpriteRendererComponent() { delete renderTarget; }
	virtual void Update();

	void SetTexture(const char* imageURL);
	void SetPosition(float x, float y);
	void SetOrientation(sf::Angle inOrientation);
	void SetScale(float x, float y);

private:
	sf::RenderTarget* renderTarget;
	sf::Texture texture;
	sf::Sprite sprite;
};