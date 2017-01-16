#pragma once

#include <FrostyCore.h>
#include <FrostyGraphics.h>

struct FROSTY_CORE_API Material
{
	Texture* DiffuseTexture;
	Colour DiffuseColour;

	inline Material() : Material(nullptr, Vector3f::One) {}
	inline Material(const Colour& diffuseColour) : Material(nullptr, diffuseColour) {}
	
	inline Material(Texture* diffuseTexture) : Material(diffuseTexture, Colour::White) {}
	inline Material(Texture* diffuseTexture, const Colour& diffuseColour) : DiffuseTexture(diffuseTexture), DiffuseColour(diffuseColour) {}
	inline ~Material() { delete this->DiffuseTexture; }
};