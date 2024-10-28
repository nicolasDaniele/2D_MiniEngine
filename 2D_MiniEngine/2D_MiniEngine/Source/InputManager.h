#pragma once

#include <SFML/Window/Keyboard.hpp>

enum InputKey 
{
	INPUT_KEY_LEFT,
	INPUT_KEY_RIGHT,
	INPUT_KEY_UP,
	INPUT_KEY_DOWN,
	INPUT_KEY_ESCAPE
};

enum KeyState 
{
	KS_UNPRESSED,
	KS_PRESSED,
	KS_HELD
};

struct InputState 
{
	KeyState left;
	KeyState right;
	KeyState up;
	KeyState down;
	KeyState escape;
};

class InputManager
{
public:
	InputState inputState = InputState();

	void InitInput();
	void Update();

private:
	void UpdateKeyState(int currentState, KeyState* keyState);
	int GetCurrentKeyState(sf::Keyboard::Key key);
};