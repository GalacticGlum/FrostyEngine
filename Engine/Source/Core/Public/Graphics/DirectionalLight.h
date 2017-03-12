#pragma once

#include <FrostyCore.h>
#include <FrostyMath.h>

#include <Graphics/Light.h>

struct FROSTY_CORE_API DirectionalLight
{
	inline DirectionalLight(const Light& light = Light(), const Vector3f& direction = Vector3f::Zero) :
		BaseLight(light), Direction(direction.Normalized()) {}

	Light BaseLight;
	Vector3f Direction;
};