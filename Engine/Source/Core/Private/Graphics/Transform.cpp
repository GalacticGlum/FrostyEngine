#include <Graphics/Transform.h>
#include <FrostyGraphics.h>

Transform::Transform() : m_Position(Vector3f::Zero), m_Rotation(Vector3f::Zero), m_Scale(Vector3f::One), m_Camera(new Camera()) {}
Transform::~Transform()
{
	delete this->m_Camera;
}

Matrix4f Transform::GetTransformation()
{
	Matrix4f translation = Matrix4f::Translate(this->m_Position);
	Matrix4f rotation = Matrix4f::Rotate(this->m_Rotation);
	Matrix4f scale = Matrix4f::Scale(this->m_Scale);

	return translation * rotation * scale;
}

void Transform::Update()
{
	this->m_Camera->Update();
}

Matrix4f Transform::GetProjectedTransformation()
{
	Matrix4f transformation = this->GetTransformation();
	Matrix4f projection = Matrix4f::Perspective(this->FOV, this->WIDTH / this->HEIGHT, this->Z_NEAR, this->Z_FAR);

	Matrix4f cameraRotation = Matrix4f::Rotate(this->m_Camera->GetForward(), this->m_Camera->GetUp());
	Matrix4f cameraTransformation = Matrix4f::Translate(this->m_Camera->GetPosition().Negative());

	return projection * cameraRotation * cameraTransformation * transformation;
}