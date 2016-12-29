#pragma once

#include <FrostyCore.h>
#include <FrostyMath.h>

struct FROSTY_CORE_API Vertex
{
public:
	Vector3f Position;
	Vertex(Vector3f& position) : Position(position) {}
};