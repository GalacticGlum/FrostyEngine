#include <Graphics/Shaders/PhongShader.h>

PhongShader::PhongShader() : Shader("Assets/Shaders/phongVertex.shader", "Assets/Shaders/phongFragment.shader"), 
	m_DirectionalLight(DirectionalLight(Light(Colour::White, 0), Vector3f::Zero))
{
	this->m_AmbientColour = Colour::White;

	this->AddUniform("mvpMatrix");
	this->AddUniform("transformation");

	this->AddUniform("materialColour");
	this->AddUniform("ambientColour");

	this->AddUniform("cameraPosition");
	this->AddUniform("specularIntensity");
	this->AddUniform("specularPower");

	this->AddUniform("directionalLight.baseLight.colour");
	this->AddUniform("directionalLight.baseLight.intensity");
	this->AddUniform("directionalLight.direction");
}

void PhongShader::Update(const Matrix4f& world, const Camera& camera, const Material& material)
{
	if (material.DiffuseTexture != nullptr)
	{
		material.DiffuseTexture->Bind(0);
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	this->SetUniform("mvpMatrix", camera.GetViewProjection() * world);
	this->SetUniform("transformation", world);

	this->SetUniform("materialColour", material.DiffuseColour, false);
	this->SetUniform("ambientColour", this->m_AmbientColour, false);
	this->SetUniform("directionalLight", this->m_DirectionalLight);

	this->SetUniform("specularIntensity", material.SpecularIntensity);
	this->SetUniform("specularPower", material.SpecularPower);
	this->SetUniform("cameraPosition", camera.GetPosition());
}