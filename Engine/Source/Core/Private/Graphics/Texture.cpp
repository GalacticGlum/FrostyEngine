#include <Graphics/Texture.h>

#define STB_IMAGE_IMPLEMENTATION
#include <STB/stb_image.h>

#include <cassert>

GLuint Texture::m_LastBindID = 0;
Texture::Texture(const std::string& filePath, GLenum textureTarget, GLfloat filter)
{
	int width;
	int height;
	int channel;

	unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &channel, 4);
	if (data == nullptr)
	{
		std::cout << "Texture::Texture(const std::string& filePath): Error loading texture: '" << filePath << "'\n";
		exit(1);
	}

	this->Initialize(width, height, data, textureTarget, filter);
	stbi_image_free(data);
}

Texture::Texture(int width, int height, unsigned char* data, GLenum textureTarget, GLfloat filter)
{
	this->Initialize(width, height, data, textureTarget, filter);
}

Texture::~Texture()
{
	glDeleteTextures(1, &this->m_TextureID);
}

void Texture::Initialize(int width, int height, unsigned char* data, GLenum textureTarget, GLfloat filter)
{
	this->m_TextureTarget = textureTarget;

	if (width > 0 && height > 0 && data != 0)
	{
		glGenTextures(1, &this->m_TextureID);
		glBindTexture(textureTarget, this->m_TextureID);
		glTexParameterf(textureTarget, GL_TEXTURE_MIN_FILTER, filter);
		glTexParameterf(textureTarget, GL_TEXTURE_MAG_FILTER, filter);
		glTexImage2D(textureTarget, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		this->m_TextureID = 0;
	}
}

void Texture::Bind(unsigned int unit) const
{
	// Make sure we aren't binding the same texture again
	if (Texture::m_LastBindID != this->m_TextureID)
	{
		// Make sure unit is not out of range
		assert(unit >= 0 && unit <= 31);

		glActiveTexture(GL_TEXTURE0 + unit);
		glBindTexture(this->m_TextureTarget, this->m_TextureID);
		Texture::m_LastBindID = this->m_TextureID;
	} 
}