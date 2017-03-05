#include <Graphics/Shaders/PhongShader.h>

PhongShader::PhongShader() : Shader("Assets/Shaders/phongVertex.shader", "Assets/Shaders/phongFragment.shader"), 
	m_DirectionalLight(DirectionalLight(Light(Colour::White, 0), Vector3f::Zero))
{
	this->m_PointLights = nullptr;
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

	for (int i = 0; i < 10; i++)
	{
		std::string name = "pointLights[" + std::to_string(i) + "]";

		this->AddUniform(name + ".baseLight.colour");
		this->AddUniform(name + ".baseLight.intensity");

		this->AddUniform(name + ".attenuation.constantFactor");
		this->AddUniform(name + ".attenuation.linearFactor");
		this->AddUniform(name + ".attenuation.exponentialFactor");

		this->AddUniform(name + ".position");
		this->AddUniform(name + ".radius");
	}
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

	for (int i = 0; i < this->m_ActivePointLights; i++)
	{
		this->SetUniform("pointLights[" + std::to_string(i) + "]", this->m_PointLights[i]);
	}
}

void PhongShader::SetPointLights(PointLight* pointLights, int size)
{
	if (size > 10)
	{
		std::cerr << "PhongShader::SetPointLights: Too many point lights!\n";
	}
	else
	{
		this->m_ActivePointLights = size;
		this->m_PointLights = pointLights;
	}
}

