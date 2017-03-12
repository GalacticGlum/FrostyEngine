#pragma once

#include <FrostyCore.h>

struct FROSTY_CORE_API AttenuationCurve
{
	float ConstantFactor;
	float LinearFactor;
	float ExponentialFactor;

	inline AttenuationCurve(float constant = 0, float linear = 0, float exponential = 0) : 
		ConstantFactor(constant), LinearFactor(linear), ExponentialFactor(exponential) {}
};