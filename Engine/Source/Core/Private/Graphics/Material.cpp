#include <Graphics/Material.h>

Material::Material(const std::string& diffuseTextureFilePath, const Colour& diffuseColour) : 
	DiffuseColour(diffuseColour), SpecularIntensity(2), SpecularPower(32)
{
	this->DiffuseTexture = std::make_unique<Texture>(diffuseTextureFilePath);
}