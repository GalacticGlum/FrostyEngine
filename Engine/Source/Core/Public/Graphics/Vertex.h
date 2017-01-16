#pragma once

#include <FrostyCore.h>
#include <FrostyMath.h>

struct FROSTY_CORE_API Vertex
{
	Vector3f Position;
	Vector2f TextureCoordinate;

	Vertex(Vector3f position, Vector2f textureCoordinate) : Position(position), TextureCoordinate(textureCoordinate) {}
};