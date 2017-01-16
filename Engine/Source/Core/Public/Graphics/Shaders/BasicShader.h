#pragma once

#include <FrostyCore.h>
#include <FrostyGraphics.h>
#include <Graphics/Material.h>

class FROSTY_CORE_API BasicShader : public Shader
{
public:
	static BasicShader* GetInstance()
	{
		static BasicShader instance;
		return &instance;
	}

	void Update(const Matrix4f& world, const Matrix4f& projection, const Material& material);
private:
	BasicShader();
};