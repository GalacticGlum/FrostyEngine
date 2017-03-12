#pragma once

#include <FrostyCore.h>
#include <Colour.h>

struct FROSTY_CORE_API Light
{
	Colour LightColour;
	float Intensity;

	inline Light(const Colour& colour = Colour::Black, float intensity = 0) : 
		LightColour(colour), Intensity(intensity) {}
};