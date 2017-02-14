#pragma once

#include <FrostyCore.h>
#include <FrostyGraphics.h>
#include <Graphics/Material.h>

class FROSTY_CORE_API PhongShader : public Shader 
{
public:
	static PhongShader* GetInstance()
	{
		static PhongShader instance;
		return &instance;
	}

	void Update(const Matrix4f& world, const Matrix4f& projection, const Material& material);

	inline const Colour& GetAmbientColour() { return this->m_AmbientColour; }
	inline void SetAmbientColour(const Vector3f& ambientColour) { this->m_AmbientColour = ambientColour; }
private:
	PhongShader();
	Colour m_AmbientColour;
};