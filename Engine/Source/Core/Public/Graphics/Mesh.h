#pragma once

#include <GL/glew.h>

#include <FrostyCommon.h>
#include <FrostyCore.h>
#include <Graphics/Vertex.h>

class FROSTY_CORE_API Mesh
{
public:
	Mesh(Vertex* vertices, int verticesSize, int* indices, int indiceSize);
	~Mesh();

	void Draw() const;
private:
	Mesh(Mesh& mesh);
	void operator=(Mesh& mesh) {}

	GLuint m_VertexBuffer;
	GLuint m_IndiceBuffer;
	int m_Size;
};