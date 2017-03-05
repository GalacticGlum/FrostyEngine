#pragma once

#include <memory>

#include <FrostyCore.h>
#include <FrostyGraphics.h>

struct FROSTY_CORE_API Material
{
	std::unique_ptr<Texture> DiffuseTexture;
	Colour DiffuseColour;

	inline Material() : Material(nullptr, Vector3f::One) {}
	inline Material(const Colour& diffuseColour) : DiffuseColour(diffuseColour) {}
	
	inline Material(const std::string& diffuseTextureFilePath) : Material(diffuseTextureFilePath, Colour::White) {}
	Material(const std::string& diffuseTextureFilePath, const Colour& diffuseColour);
};