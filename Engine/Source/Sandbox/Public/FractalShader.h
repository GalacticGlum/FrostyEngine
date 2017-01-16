#pragma once

#include <FrostyGraphics.h>
#include <Graphics/Material.h>

class FractalShader : public Shader
{
public:
	static FractalShader* GetInstance()
	{
		static FractalShader instance;
		return &instance;
	}
private:
	inline FractalShader() : Shader("Assets/Shaders/fractalVertex.shader", "Assets/Shaders/fractalFragment.shader") {}
};