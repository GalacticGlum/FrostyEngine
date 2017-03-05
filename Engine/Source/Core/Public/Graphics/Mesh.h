#pragma once

#include <FrostyCommon.h>
#include <FrostyCore.h>
#include <FrostyGraphics.h>

class FROSTY_CORE_API Mesh
{
public:
	Mesh(const std::string& filePath);
	Mesh(Vertex* vertices, int verticesSize, int* indices, int indexCount);
	~Mesh();

	void Draw() const;
private:
	Mesh(Mesh& mesh);
	void operator=(Mesh& mesh) {}

	void CalculateNormals(Vertex* vertices, int verticesSize, int* indices, int indexCount);

	GLuint m_VertexBuffer;
	GLuint m_IndexBuffer;
	GLuint m_Size;
};