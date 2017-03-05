#pragma once

#include <FrostyCore.h>
#include <Colour.h>

struct FROSTY_CORE_API Light
{
public:
	inline Light(const Colour& colour, float intensity) : 
		LightColour(colour), Intensity(intensity) {}

	Colour LightColour;
	float Intensity;
};