#include <Graphics/Shaders/PhongShader.h>

PhongShader::PhongShader() : Shader("Assets/Shaders/phongVertex.shader", "Assets/Shaders/phongFragment.shader")
{
	this->m_AmbientColour = Colour::White;

	this->AddUniform("mvpMatrix");
	this->AddUniform("materialColour");
	this->AddUniform("ambientColour");
}

void PhongShader::Update(const Matrix4f& world, const Matrix4f& projection, const Material& material)
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
	this->SetUniform("materialColour", material.DiffuseColour, false);
	this->SetUniform("ambientColour", this->m_AmbientColour, false);
}