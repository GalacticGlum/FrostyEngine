#include <Graphics/Material.h>

Material::Material(const std::string& diffuseTextureFilePath, const Colour& diffuseColour)
{
	this->DiffuseTexture = std::make_unique<Texture>(diffuseTextureFilePath);
	this->DiffuseColour = diffuseColour;
}