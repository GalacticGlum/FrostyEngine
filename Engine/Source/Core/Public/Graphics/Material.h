#pragma once

#include <memory>

#include <FrostyCore.h>
#include <FrostyGraphics.h>

struct FROSTY_CORE_API Material
{
	std::unique_ptr<Texture> DiffuseTexture;
	Colour DiffuseColour;

	float SpecularIntensity;
	float SpecularPower;

	inline Material() : Material(Colour::White) {}
	inline Material(const Colour& diffuseColour) : DiffuseColour(diffuseColour), SpecularIntensity(2), SpecularPower(32) {}
	
	inline Material(const std::string& diffuseTextureFilePath) : Material(diffuseTextureFilePath, Colour::White) {}
	Material(const std::string& diffuseTextureFilePath, const Colour& diffuseColour);
};