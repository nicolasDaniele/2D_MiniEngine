#pragma once

struct Position
{
	float x;
	float y;
};

struct Scale
{
	float x;
	float y;
};

struct Transform
{
	Position position;
	float orientation;
	Scale scale;

	Transform()
	{
		position.x = 0.0f;
		position.y = 0.0f;

		orientation = 0.0f;

		scale.x = 1.0f;
		scale.y = 1.0f;
	}
};