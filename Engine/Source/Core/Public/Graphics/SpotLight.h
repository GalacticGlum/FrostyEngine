#pragma once

#include <FrostyCore.h>
#include <FrostyMath.h>

#include <Graphics/PointLight.h>

struct FROSTY_CORE_API SpotLight
{
	PointLight BaseLight;
	Vector3f Direction;
	float Cutoff;

	inline SpotLight(const PointLight& light = PointLight(), const Vector3f& direction = Vector3f::One, float cutoff = 0) :
		BaseLight(light), Direction(direction.Normalized()), Cutoff(cutoff) {}
};

