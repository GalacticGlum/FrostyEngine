#pragma once

#include <FrostyCore.h>
#include <FrostyMath.h>

#include <Graphics/Light.h>

struct FROSTY_CORE_API DirectionalLight
{
public:
	inline DirectionalLight(const Light& light, const Vector3f& direction) :
		BaseLight(light), Direction(direction.Normalized()) {}

	Light BaseLight;
	Vector3f Direction;
};