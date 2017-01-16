#include <Graphics/Shaders/BasicShader.h>

BasicShader::BasicShader() : Shader("Assets/Shaders/basicVertex.shader", "Assets/Shaders/basicFragment.shader")
{
	this->AddUniform("mvpMatrix");
	this->AddUniform("colour");
}

void BasicShader::Update(const Matrix4f& world, const Matrix4f& projection, const Material& material)
{
	if (material.DiffuseTexture != nullptr)
	{
		material.DiffuseTexture->Bind(0);
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	this->SetUniform("mvpMatrix", projection);
	this->SetUniform("colour", material.DiffuseColour, false);
}