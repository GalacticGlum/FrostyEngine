#include <Graphics/Mesh.h>

Mesh::Mesh(Vertex* vertices, int verticesSize, int* indices, int indiceSize)
{
	this->m_Size = indiceSize;

	glGenBuffers(1, &this->m_VertexBuffer);
	glGenBuffers(1, &this->m_IndiceBuffer);

	glBindBuffer(GL_ARRAY_BUFFER, this->m_VertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, verticesSize * sizeof(Vertex), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_IndiceBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indiceSize * sizeof(int), indices, GL_STATIC_DRAW);
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &this->m_VertexBuffer);
	glDeleteBuffers(1, &this->m_IndiceBuffer);
}

void Mesh::Draw() const
{
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, this->m_VertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_IndiceBuffer);
	glDrawElements(GL_TRIANGLES, this->m_Size, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
}