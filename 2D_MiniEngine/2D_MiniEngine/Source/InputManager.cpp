#include "InputManager.h"
#include <stdio.h>

void InputManager::Update() 
{
	UpdateKeyState(GetCurrentKeyState(sf::Keyboard::A), &inputState.left);
	UpdateKeyState(GetCurrentKeyState(sf::Keyboard::D), &inputState.right);
	UpdateKeyState(GetCurrentKeyState(sf::Keyboard::W), &inputState.up);
	UpdateKeyState(GetCurrentKeyState(sf::Keyboard::S), &inputState.down);
	UpdateKeyState(GetCurrentKeyState(sf::Keyboard::Escape), &inputState.escape);
}

int InputManager::GetCurrentKeyState(sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key) ? 1 : 0;
}

void InputManager::UpdateKeyState(int currentState, KeyState* keyState)
{
	if (currentState) 
	{
		if (*keyState > 0)
			*keyState = KS_HELD;
		else
			*keyState = KS_PRESSED;
	}
	else 
	{
		*keyState = KS_UNPRESSED;
	}
}