#include <Graphics/Transform.h>

Matrix4f Transform::GetTransformationMatrix()
{
	Matrix4f translation = Matrix4f::Translate(this->m_Position);
	Matrix4f rotation = Matrix4f::Rotate(this->m_Rotation);
	Matrix4f scale = Matrix4f::Scale(this->m_Scale);

	//return translation * this->m_Rotation.ToRotationMatrix() * scale;
	return scale * rotation * translation;
}

Matrix4f Transform::GetProjectionMatrix()
{
	float width = Application::GetGameEngineInstance()->GetWindow()->GetWidth();
	float height = Application::GetGameEngineInstance()->GetWindow()->GetHeight();
	Matrix4f projectionMatrix = Matrix4f::Perspective(70.0f, width / height, 0.01f, 1000.0f);
	Matrix4f cameraTranslation = Matrix4f::Translate(-Camera::GetInstance()->GetPosition());

	return projectionMatrix * cameraTranslation * this->GetTransformationMatrix();
}

//void Transform::Rotate(const Vector3f& axis, float angle)
//{
//	this->Rotate(Quaternion(axis, angle));
//}
//
//void Transform::Rotate(const Quaternion& rotation)
//{
//	this->m_Rotation = Quaternion((rotation * this->m_Rotation).Normalize());
//}