#pragma once

#include <FrostyCore.h>

struct FROSTY_CORE_API AttenuationCurve
{
	float ConstantFactor;
	float LinearFactor;
	float ExponentialFactor;

	inline AttenuationCurve(float constant, float linear, float exponential) : 
		ConstantFactor(constant), LinearFactor(linear), ExponentialFactor(exponential) {}
};