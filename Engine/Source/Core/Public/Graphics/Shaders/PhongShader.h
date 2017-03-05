#pragma once

#include <FrostyCore.h>
#include <FrostyGraphics.h>
#include <Graphics/Material.h>

#include <Graphics/Light.h>
#include <Graphics/DirectionalLight.h>
#include <Graphics/PointLight.h>

class FROSTY_CORE_API PhongShader : public Shader 
{
public:
	static PhongShader* GetInstance()
	{
		static PhongShader instance;
		return &instance;
	}

	void Update(const Matrix4f& world, const Camera& camera, const Material& material);

	inline const Colour& GetAmbientColour() { return this->m_AmbientColour; }
	inline void SetAmbientColour(const Colour& ambientColour) { this->m_AmbientColour = ambientColour; }

	inline const DirectionalLight& GetDirectionalLight() { return this->m_DirectionalLight; }
	inline void SetDirectionalLight(const DirectionalLight& light) { this->m_DirectionalLight = light; }

	void SetPointLights(PointLight* pointLights, int size);
private:
	PhongShader();

	Colour m_AmbientColour;
	DirectionalLight m_DirectionalLight;

	int m_ActivePointLights;
	PointLight* m_PointLights;
};