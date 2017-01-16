#pragma once

#include <iostream>

#include <FrostyCore.h>
#include <FrostyGraphics.h>

class FROSTY_CORE_API Texture
{
public:
	inline Texture(const std::string& filePath) : Texture(filePath, GL_TEXTURE_2D, GL_LINEAR) {}
	Texture(const std::string& filePath, GLenum textureTarget, GLfloat filter);

	inline Texture(int width, int height, unsigned char* data) : Texture(width, height, data, GL_TEXTURE_2D, GL_LINEAR) {}
	Texture(int width, int height, unsigned char* data, GLenum textureTarget, GLfloat filter);
	~Texture();

	void Bind(unsigned int unit) const;
private:
	GLenum m_TextureTarget;
	GLuint m_TextureID;

	void Initialize(int width, int height, unsigned char* data, GLenum textureTarget, GLfloat filter);
	static const Texture* m_LastBind;
};