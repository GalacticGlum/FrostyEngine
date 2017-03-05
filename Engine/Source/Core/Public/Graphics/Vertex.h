#pragma once

#include <FrostyCore.h>
#include <FrostyMath.h>

struct FROSTY_CORE_API Vertex
{
	Vector3f Position;
	Vector2f TextureCoordinate;
	Vector3f Normal;

	inline Vertex(Vector3f position) : Position(position), TextureCoordinate(Vector2f::Zero) {}
	inline Vertex(Vector3f position, Vector2f textureCoordinate) : Position(position), TextureCoordinate(textureCoordinate), Normal(Vector3f::Zero) {}
	inline Vertex(Vector3f position, Vector2f textureCoordinate, Vector3f normal) : Position(position), TextureCoordinate(textureCoordinate), Normal(normal) {}
};