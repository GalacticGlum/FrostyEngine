#include <Graphics/Mesh.h>

#include <iostream>

Mesh::Mesh(const std::string& filePath)
{
	std::cout << "Mesh::Mesh(const std::string& filePath): Mesh loading via file is not supported!\n";
	// TODO: Mesh file Loading
}

Mesh::Mesh(Vertex* vertices, int verticesSize, int* indices, int indexCount, bool calculateNormals /* = false */)
{
	this->m_Size = indexCount;
	if (calculateNormals)
	{
		this->CalculateNormals(vertices, verticesSize, indices, indexCount);
	}

	glGenBuffers(1, &this->m_VertexBuffer);
	glGenBuffers(1, &this->m_IndexBuffer);

	glBindBuffer(GL_ARRAY_BUFFER, this->m_VertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, verticesSize * sizeof(Vertex), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_IndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(int), indices, GL_STATIC_DRAW);
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &this->m_VertexBuffer);
	glDeleteBuffers(1, &this->m_IndexBuffer);
}

void Mesh::Draw() const
{
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, this->m_VertexBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)sizeof(Vector3f));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(Vector3f) + sizeof(Vector2f)));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_IndexBuffer);
	glDrawElements(GL_TRIANGLES, this->m_Size, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}

void Mesh::CalculateNormals(Vertex* vertices, int verticesSize, int* indices, int indexCount)
{
	for (int i = 0; i < indexCount; i += 3)
	{
		int i0 = indices[i];
		int i1 = indices[i + 1];
		int i2 = indices[i + 2];

		Vector3f v1 = vertices[i1].Position - vertices[i0].Position;
		Vector3f v2 = vertices[i2].Position - vertices[i0].Position;

		Vector3f normal = v1.Cross(v2).Normalized();
		vertices[i0].Normal += normal;
		vertices[i1].Normal += normal;
		vertices[i2].Normal += normal;
	}

	for (int i = 0; i < verticesSize; i++)
	{
		vertices[i].Normal = vertices[i].Normal.Normalized();
	}
}