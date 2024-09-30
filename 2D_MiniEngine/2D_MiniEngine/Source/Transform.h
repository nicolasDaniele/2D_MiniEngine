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
};