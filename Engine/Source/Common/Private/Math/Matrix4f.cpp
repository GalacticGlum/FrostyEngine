#include <Math/Matrix4f.h>
#include <Math/Quaternion.h>

const Matrix4f Matrix4f::Identity = Matrix4f(1);

Matrix4f::Matrix4f(float scalar)
{
	memset(this->Elements, 0, 16 * sizeof(float));
	this->Elements[0 + 0 * 4] = scalar;
	this->Elements[1 + 1 * 4] = scalar;
	this->Elements[2 + 2 * 4] = scalar;
	this->Elements[3 + 3 * 4] = scalar;
}

Matrix4f::Matrix4f(const Vector4f& row0, const Vector4f& row1, const Vector4f& row2, const Vector4f& row3)
{
	Rows[0] = row0;
	Rows[1] = row1;
	Rows[2] = row2;
	Rows[3] = row3;
}

Matrix4f& Matrix4f::Multiply(const Matrix4f& matrix)
{
	float data[16];
	for (int32_t row = 0; row < 4; row++)
	{
		for (int32_t column = 0; column < 4; column++)
		{
			float s = 0;
			for (int32_t k = 0; k < 4; k++)
			{
				s += this->Elements[k + row * 4] * matrix.Elements[k + column * 4];
			}
			data[column + row * 4] = s;
		}
	}
	memcpy(this->Elements, data, 16 * sizeof(float));
	return (*this);
}

Vector4f Matrix4f::Multiply(const Vector4f& vector) const
{
	return vector.Multiply(*this);
}

Vector3f Matrix4f::Multiply(const Vector3f& vector) const
{
	return vector.Multiply(*this);
}

Matrix4f& Matrix4f::Invert()
{
	float tempMatrix[16];

	tempMatrix[0] = this->Elements[5] * this->Elements[10] * this->Elements[15] -
					this->Elements[5] * this->Elements[11] * this->Elements[14] -
					this->Elements[9] * this->Elements[6] * this->Elements[15] +
					this->Elements[9] * this->Elements[7] * this->Elements[14] +
					this->Elements[13] * this->Elements[6] * this->Elements[11] -
					this->Elements[13] * this->Elements[7] * this->Elements[10];

	tempMatrix[4] = -this->Elements[4] * this->Elements[10] * this->Elements[15] +
					this->Elements[4] * this->Elements[11] * this->Elements[14] +
					this->Elements[8] * this->Elements[6] * this->Elements[15] -
					this->Elements[8] * this->Elements[7] * this->Elements[14] -
					this->Elements[12] * this->Elements[6] * this->Elements[11] +
					this->Elements[12] * this->Elements[7] * this->Elements[10];

	tempMatrix[8] = this->Elements[4] * this->Elements[9] * this->Elements[15] -
					this->Elements[4] * this->Elements[11] * this->Elements[13] -
					this->Elements[8] * this->Elements[5] * this->Elements[15] +
					this->Elements[8] * this->Elements[7] * this->Elements[13] +
					this->Elements[12] * this->Elements[5] * this->Elements[11] -
					this->Elements[12] * this->Elements[7] * this->Elements[9];

	tempMatrix[12] = -this->Elements[4] * this->Elements[9] * this->Elements[14] +
					this->Elements[4] * this->Elements[10] * this->Elements[13] +
					this->Elements[8] * this->Elements[5] * this->Elements[14] -
					this->Elements[8] * this->Elements[6] * this->Elements[13] -
					this->Elements[12] * this->Elements[5] * this->Elements[10] +
					this->Elements[12] * this->Elements[6] * this->Elements[9];

	tempMatrix[1] = -this->Elements[1] * this->Elements[10] * this->Elements[15] +
					this->Elements[1] * this->Elements[11] * this->Elements[14] +
					this->Elements[9] * this->Elements[2] * this->Elements[15] -
					this->Elements[9] * this->Elements[3] * this->Elements[14] -
					this->Elements[13] * this->Elements[2] * this->Elements[11] +
					this->Elements[13] * this->Elements[3] * this->Elements[10];

	tempMatrix[5] = this->Elements[0] * this->Elements[10] * this->Elements[15] -
					this->Elements[0] * this->Elements[11] * this->Elements[14] -
					this->Elements[8] * this->Elements[2] * this->Elements[15] +
					this->Elements[8] * this->Elements[3] * this->Elements[14] +
					this->Elements[12] * this->Elements[2] * this->Elements[11] -
					this->Elements[12] * this->Elements[3] * this->Elements[10];

	tempMatrix[9] = -this->Elements[0] * this->Elements[9] * this->Elements[15] +
					this->Elements[0] * this->Elements[11] * this->Elements[13] +
					this->Elements[8] * this->Elements[1] * this->Elements[15] -
					this->Elements[8] * this->Elements[3] * this->Elements[13] -
					this->Elements[12] * this->Elements[1] * this->Elements[11] +
					this->Elements[12] * this->Elements[3] * this->Elements[9];

	tempMatrix[13] = this->Elements[0] * this->Elements[9] * this->Elements[14] -
					this->Elements[0] * this->Elements[10] * this->Elements[13] -
					this->Elements[8] * this->Elements[1] * this->Elements[14] +
					this->Elements[8] * this->Elements[2] * this->Elements[13] +
					this->Elements[12] * this->Elements[1] * this->Elements[10] -
					this->Elements[12] * this->Elements[2] * this->Elements[9];

	tempMatrix[2] = this->Elements[1] * this->Elements[6] * this->Elements[15] -
					this->Elements[1] * this->Elements[7] * this->Elements[14] -
					this->Elements[5] * this->Elements[2] * this->Elements[15] +
					this->Elements[5] * this->Elements[3] * this->Elements[14] +
					this->Elements[13] * this->Elements[2] * this->Elements[7] -
					this->Elements[13] * this->Elements[3] * this->Elements[6];

	tempMatrix[6] = -this->Elements[0] * this->Elements[6] * this->Elements[15] +
					this->Elements[0] * this->Elements[7] * this->Elements[14] +
					this->Elements[4] * this->Elements[2] * this->Elements[15] -
					this->Elements[4] * this->Elements[3] * this->Elements[14] -
					this->Elements[12] * this->Elements[2] * this->Elements[7] +
					this->Elements[12] * this->Elements[3] * this->Elements[6];

	tempMatrix[10] = this->Elements[0] * this->Elements[5] * this->Elements[15] -
					this->Elements[0] * this->Elements[7] * this->Elements[13] -
					this->Elements[4] * this->Elements[1] * this->Elements[15] +
					this->Elements[4] * this->Elements[3] * this->Elements[13] +
					this->Elements[12] * this->Elements[1] * this->Elements[7] -
					this->Elements[12] * this->Elements[3] * this->Elements[5];

	tempMatrix[14] = -this->Elements[0] * this->Elements[5] * this->Elements[14] +
					this->Elements[0] * this->Elements[6] * this->Elements[13] +
					this->Elements[4] * this->Elements[1] * this->Elements[14] -
					this->Elements[4] * this->Elements[2] * this->Elements[13] -
					this->Elements[12] * this->Elements[1] * this->Elements[6] +
					this->Elements[12] * this->Elements[2] * this->Elements[5];

	tempMatrix[3] = -this->Elements[1] * this->Elements[6] * this->Elements[11] +
					this->Elements[1] * this->Elements[7] * this->Elements[10] +
					this->Elements[5] * this->Elements[2] * this->Elements[11] -
					this->Elements[5] * this->Elements[3] * this->Elements[10] -
					this->Elements[9] * this->Elements[2] * this->Elements[7] +
					this->Elements[9] * this->Elements[3] * this->Elements[6];

	tempMatrix[7] = this->Elements[0] * this->Elements[6] * this->Elements[11] -
					this->Elements[0] * this->Elements[7] * this->Elements[10] -
					this->Elements[4] * this->Elements[2] * this->Elements[11] +
					this->Elements[4] * this->Elements[3] * this->Elements[10] +
					this->Elements[8] * this->Elements[2] * this->Elements[7] -
					this->Elements[8] * this->Elements[3] * this->Elements[6];

	tempMatrix[11] = -this->Elements[0] * this->Elements[5] * this->Elements[11] +
					this->Elements[0] * this->Elements[7] * this->Elements[9] +
					this->Elements[4] * this->Elements[1] * this->Elements[11] -
					this->Elements[4] * this->Elements[3] * this->Elements[9] -
					this->Elements[8] * this->Elements[1] * this->Elements[7] +
					this->Elements[8] * this->Elements[3] * this->Elements[5];

	tempMatrix[15] = this->Elements[0] * this->Elements[5] * this->Elements[10] -
					this->Elements[0] * this->Elements[6] * this->Elements[9] -
					this->Elements[4] * this->Elements[1] * this->Elements[10] +
					this->Elements[4] * this->Elements[2] * this->Elements[9] +
					this->Elements[8] * this->Elements[1] * this->Elements[6] -
					this->Elements[8] * this->Elements[2] * this->Elements[5];

	float d = 1.0f / (this->Elements[0] * tempMatrix[0] +
              this->Elements[1] * tempMatrix[4] +
              this->Elements[2] * tempMatrix[8] +
              this->Elements[3] * tempMatrix[12]);

	// Copy data
	for (int32_t i = 0; i < 16; i++)
	{
		this->Elements[i] = tempMatrix[i] * d;
	}

	return *this;
}

Matrix4f Matrix4f::Inverted() const 
{
	Matrix4f result = *this;
	return result.Invert();
}

Vector4f Matrix4f::GetColumn(int idx) const
{
	return Vector4f(this->Elements[idx + 0 * 4], 
					this->Elements[idx + 1 * 4], 
					this->Elements[idx + 2 * 4], 
					this->Elements[idx + 3 * 4]);
}

void Matrix4f::SetColumn(uint32_t idx, const Vector4f& column)
{
	this->Elements[idx + 0 * 4] = column.X;
	this->Elements[idx + 1 * 4] = column.Y;
	this->Elements[idx + 2 * 4] = column.Z;
	this->Elements[idx + 3 * 4] = column.W;
}

Matrix4f Matrix4f::Orthographic(float left, float right, float bottom, float top, float near, float far)
{
	Matrix4f result(1);
	result.Elements[0 + 0 * 4] = 2.0f / (right - left);
	result.Elements[1 + 1 * 4] = 2.0f / (top - bottom);
	result.Elements[2 + 2 * 4] = 2.0f / (near - far);

	result.Elements[3 + 0 * 4] = (left + right) / (left - right);
	result.Elements[3 + 1 * 4] = (bottom + top) / (bottom - top);
	result.Elements[3 + 2 * 4] = (far + near) / (far - near);

	return result;
}

Matrix4f Matrix4f::Perspective(float fov, float aspectRatio, float near, float far)
{
	Matrix4f result(1);

	float q = 1.0f / std::tan(Mathf::DegreesToRadians(0.5f * fov));
	float a = q / aspectRatio;

	float b = (near + far) / (near - far);
	float c = (2.0f * near * far) / (near - far);

	result.Elements[0 + 0 * 4] = a;
	result.Elements[1 + 1 * 4] = q;
	result.Elements[2 + 2 * 4] = b;

	result.Elements[2 + 3 * 4] = -1.0f;
	result.Elements[3 + 2 * 4] = c;

	return result;
}

Matrix4f Matrix4f::Translate(const Vector3f& translation)
{
	Matrix4f result(1);

	result.Elements[3 + 0 * 4] = translation.X;
	result.Elements[3 + 1 * 4] = translation.Y;
	result.Elements[3 + 2 * 4] = translation.Z;

	return result;
}

Matrix4f Matrix4f::Rotate(const Vector3f& eulerAngles)
{
	Matrix4f result = Matrix4f::Identity;

	Matrix4f rx = Matrix4f();
	Matrix4f ry = Matrix4f();
	Matrix4f rz = Matrix4f();

	float x = eulerAngles.X;
	float y = eulerAngles.Y;
	float z = eulerAngles.Z;

	rz.Rows[0] = Vector4f(std::cos(z), -std::sin(z), 0, 0);
	rz.Rows[1] = Vector4f(std::sin(z), std::cos(z), 0, 0);
	rz.Rows[2] = Vector4f(0, 0, 1, 0);
	rz.Rows[3] = Vector4f(0, 0, 0, 1);

	rx.Rows[0] = Vector4f(1, 0, 0, 0);
	rx.Rows[1] = Vector4f(0, std::cos(x), -std::sin(x), 0);
	rx.Rows[2] = Vector4f(0, std::sin(x), std::cos(x), 0);
	rx.Rows[3] = Vector4f(0, 0, 0, 1);

	ry.Rows[0] = Vector4f(std::cos(y), 0, -std::sin(y), 0);
	ry.Rows[1] = Vector4f(0, 1, 0, 0);
	ry.Rows[2] = Vector4f(std::sin(y), 0, std::cos(y), 0);
	ry.Rows[3] = Vector4f(0, 0, 0, 1);

	return (rz * ry * rx);
}

Matrix4f Matrix4f::Rotate(const Vector3f& axis, float angle)
{
	Matrix4f result = Matrix4f::Identity;

	float r = Mathf::DegreesToRadians(angle);
	float c = std::cos(r);
	float s = std::sin(r);
	float mc = 1.0f - c;

	float x = axis.X;
	float y = axis.Y;
	float z = axis.Z;

	result.Elements[0 + 0 * 4] = x * mc + x;
	result.Elements[0 + 1 * 4] = y * x * mc + z * s;
	result.Elements[0 + 2 * 4] = x * z * mc - y * s;

	result.Elements[1 + 0 * 4] = x * y * mc - z * s;
	result.Elements[1 + 1 * 4] = y * mc + c;
	result.Elements[1 + 2 * 4] = y * z * mc + x * s;

	result.Elements[2 + 0 * 4] = x * z * mc + y * s;
	result.Elements[2 + 1 * 4] = y * z * mc - x * s;
	result.Elements[2 + 2 * 4] =  z * mc + c;

	return result;
}

Matrix4f Matrix4f::Rotate(const Quaternion& quaternion)
{
	Matrix4f result = Matrix4f::Identity;

	float x = quaternion.X;
	float y = quaternion.Y;
	float z = quaternion.Z;
	float w = quaternion.W;

	float x2 = (x + x);
	float y2 = (y + y);
	float z2 = (y + y);

	float x1x2 = (x * x2);
	float x1y2 = (x * y2);
	float x1z2 = (x * z2);
	float w1x2 = (w * x2);
	float y1y2 = (y * y2);
	float y1z2 = (y * z2);
	float w1y2 = (w * y2);
	float z1z2 = (z * z2);
	float w1z2 = (w * z2);

	result.Rows[0] = Vector4f(((1.0f - y1y2) - z1z2), (x1y2 - w1z2), (x1z2 + w1y2), 0.0f);
	result.Rows[1] = Vector4f((x1y2 + w1z2), ((1.0f - x1x2) - z1z2), (y1z2 - w1x2), 0.0f);
	result.Rows[2] = Vector4f((x1z2 - w1y2), (y1z2 + w1x2), ((1.0f - x1x2) - y1y2), 0.0f);
	return result;
}

Matrix4f Matrix4f::Rotate(const Vector3f& n, const Vector3f& v, const Vector3f& u)
{
	Matrix4f result = Matrix4f::Identity;

	result.Rows[0] = Vector4f(u.X, v.X, n.X, 0);
	result.Rows[1] = Vector4f(u.Y, v.Y, n.Y, 0);
	result.Rows[2] = Vector4f(u.Z, v.Z, n.Z, 0);
	result.Rows[3] = Vector4f(0, 0, 0, 1);

	return result;
}

Matrix4f Matrix4f::Scale(const Vector3f& scale)
{
	Matrix4f result(1);

	result.Elements[0 + 0 * 4] = scale.X;
	result.Elements[1 + 1 * 4] = scale.Y;
	result.Elements[2 + 2 * 4] = scale.Z;

	return result;
}

Matrix4f Matrix4f::Invert(const Matrix4f& matrix)
{
	Matrix4f result = matrix;
	return result.Invert();
}

Matrix4f Matrix4f::Transpose(const Matrix4f& matrix)
{
	return Matrix4f
	(
		Vector4f(matrix.Rows[0].X, matrix.Rows[1].X, matrix.Rows[2].X, matrix.Rows[3].X),
		Vector4f(matrix.Rows[0].Y, matrix.Rows[1].Y, matrix.Rows[2].Y, matrix.Rows[3].Y),
		Vector4f(matrix.Rows[0].Z, matrix.Rows[1].Z, matrix.Rows[2].Z, matrix.Rows[3].Z),
		Vector4f(matrix.Rows[0].W, matrix.Rows[1].W, matrix.Rows[2].W, matrix.Rows[3].W)
	);
}

Matrix4f Matrix4f::LookAt(const Vector3f& camera, const Vector3f& lookObject, const Vector3f& up)
{
	Matrix4f result = Matrix4f::Identity;
	Vector3f f = (lookObject - camera).Normalize();
	Vector3f s = f.Cross(up.Normalized());
	Vector3f u = s.Cross(f);

	result.Elements[0 + 0 * 4] = s.X;
	result.Elements[0 + 1 * 4] = s.Y;
	result.Elements[0 + 2 * 4] = s.Z;

	result.Elements[1 + 0 * 4] = u.X;
	result.Elements[1 + 1 * 4] = u.Y;
	result.Elements[1 + 2 * 4] = u.Z;

	result.Elements[2 + 0 * 4] = -f.X;
	result.Elements[2 + 1 * 4] = -f.Y;
	result.Elements[2 + 2 * 4] = -f.Z;

	return result * Matrix4f::Translate(Vector3f(-camera.X, -camera.Y, -camera.Z));
}

std::string Matrix4f::ToString() const
{
	std::stringstream result;

	result << "(" << Rows[0].X << ", " << Rows[1].X << ", " << Rows[2].X << ", " << Rows[3].X << "),\n";
	result << "(" << Rows[0].Y << ", " << Rows[1].Y << ", " << Rows[2].Y << ", " << Rows[3].Y << "),\n";
	result << "(" << Rows[0].Z << ", " << Rows[1].Z << ", " << Rows[2].Z << ", " << Rows[3].Z << "),\n";
	result << "(" << Rows[0].W << ", " << Rows[1].W << ", " << Rows[2].W << ", " << Rows[3].W << ")";	

	return result.str();
}

std::ostream& operator<<(std::ostream& stream, const Matrix4f& right)
{
	return (stream << right.ToString());
}