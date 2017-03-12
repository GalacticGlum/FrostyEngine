#pragma once

#include <FrostyCore.h>
#include <FrostyMath.h>

#include <Graphics/Light.h>
#include <Graphics/AttenuationCurve.h>

struct FROSTY_CORE_API PointLight
{
	Light BaseLight;
	AttenuationCurve Attenuation;
	Vector3f Position;
	float Radius;

	inline PointLight(const Light& BaseLight = Light(), const AttenuationCurve& attenuation = AttenuationCurve(), const Vector3f& position = Vector3f::Zero, float radius = 0) : 
		BaseLight(BaseLight), Attenuation(attenuation), Position(position), Radius(radius) {}
};