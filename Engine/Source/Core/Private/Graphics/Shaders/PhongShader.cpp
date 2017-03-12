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

	for (int i = 0; i < MAX_POINT_LIGHTS; i++)
	{
		std::ostringstream stringBuilder;
		stringBuilder << "pointLights[" << i << "]";
		std::string name = stringBuilder.str();

		this->AddUniform(name + ".baseLight.colour");
		this->AddUniform(name + ".baseLight.intensity");

		this->AddUniform(name + ".attenuation.constantFactor");
		this->AddUniform(name + ".attenuation.linearFactor");
		this->AddUniform(name + ".attenuation.exponentialFactor");

		this->AddUniform(name + ".position");
		this->AddUniform(name + ".radius");
	}

	for (int i = 0; i < MAX_SPOT_LIGHTS; i++)
	{
		std::ostringstream stringBuilder;
		stringBuilder << "spotLights[" << i << "]";
		std::string name = stringBuilder.str();

		this->AddUniform(name + ".pointLight.baseLight.colour");
		this->AddUniform(name + ".pointLight.baseLight.intensity");

		this->AddUniform(name + ".pointLight.attenuation.constantFactor");
		this->AddUniform(name + ".pointLight.attenuation.linearFactor");
		this->AddUniform(name + ".pointLight.attenuation.exponentialFactor");

		this->AddUniform(name + ".pointLight.position");
		this->AddUniform(name + ".pointLight.radius");

		this->AddUniform(name + ".direction");
		this->AddUniform(name + ".cutoff");
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

	for (int i = 0; i < this->m_ActivePointLights; i++)
	{
		std::ostringstream stringBuilder;
		stringBuilder << "pointLights[" << i << "]";
		std::string name = stringBuilder.str();

		this->SetUniform(name, this->m_PointLights[i]);
	}

	for (int i = 0; i < this->m_ActiveSpotLights; i++)
	{
		std::ostringstream stringBuilder;
		stringBuilder << "spotLights[" << i << "]";
		std::string name = stringBuilder.str();

		this->SetUniform(name, this->m_SpotLights[i]);
	}

	this->SetUniform("specularIntensity", material.SpecularIntensity);
	this->SetUniform("specularPower", material.SpecularPower);
	this->SetUniform("cameraPosition", camera.GetPosition());
}

void PhongShader::SetPointLights(PointLight* pointLights, int size)
{
	if (size > MAX_POINT_LIGHTS)
	{
		std::cerr << "PhongShader::SetPointLights: Too many point lights!\n";
	}
	else
	{
		this->m_ActivePointLights = size;
		this->m_PointLights = pointLights;
	}
}

void PhongShader::SetSpotLight(SpotLight* spotLights, int size)
{
	if(size > MAX_SPOT_LIGHTS)
	{
		std::cerr << "PhongShader::SetSpotLights: Too many spot lights!\n";
	}
	else
	{
		this->m_ActiveSpotLights = size;
		this->m_SpotLights = spotLights;
	}
}

