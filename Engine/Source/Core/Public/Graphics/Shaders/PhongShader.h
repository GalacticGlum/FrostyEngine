#pragma once

#include <FrostyCore.h>
#include <FrostyGraphics.h>
#include <Graphics/Material.h>

#include <Graphics/Light.h>
#include <Graphics/DirectionalLight.h>
#include <Graphics/PointLight.h>
#include <Graphics/SpotLight.h>

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
	void SetSpotLight(SpotLight* spotLights, int size);
private:
	const static int MAX_POINT_LIGHTS = 10;
	const static int MAX_SPOT_LIGHTS = 10;

	PhongShader();

	Colour m_AmbientColour;
	DirectionalLight m_DirectionalLight;

	int m_ActivePointLights;
	int m_ActiveSpotLights;

	PointLight* m_PointLights;
	SpotLight* m_SpotLights;
};