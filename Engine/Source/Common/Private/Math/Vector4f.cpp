#include <Math/Vector4f.h>
#include <Math/Matrix4f.h>

const Vector4f Vector4f::Zero = Vector4f{ 0, 0, 0, 0 };
const Vector4f Vector4f::One = Vector4f{ 1, 1, 1, 1 };

Vector4f::Vector4f(const Vector3f& vector, float w) : X(vector.X), Y(vector.Y), Z(vector.Z), W(w)
{
}

Vector4f& Vector4f::Add(const Vector4f& right)
{
	this->X += right.X;
	this->Y += right.Y;
	this->Z += right.Z;
	this->W += right.W;

	return *this;
}

Vector4f& Vector4f::Subtract(const Vector4f& right)
{
	this->X -= right.X;
	this->Y -= right.Y;
	this->Z -= right.Z;
	this->W -= right.W;

	return *this;
}

Vector4f& Vector4f::Multiply(const Vector4f& right)
{
	this->X *= right.X;
	this->Y *= right.Y;
	this->Z *= right.Z;
	this->W *= right.W;

	return *this;
}

Vector4f& Vector4f::Divide(const Vector4f& right)
{
	this->X /= right.X;
	this->Y /= right.Y;
	this->Z /= right.Z;
	this->W /= right.W;

	return *this;
}

Vector4f Vector4f::Multiply(const Matrix4f& matrix) const
{
	return Vector4f
	(
		matrix.Rows[0].X * this->X + matrix.Rows[0].Y * this->Y + matrix.Rows[0].Z * this->Z + matrix.Rows[0].W * this->W,
		matrix.Rows[1].X * this->X + matrix.Rows[1].Y * this->Y + matrix.Rows[1].Z * this->Z + matrix.Rows[1].W * this->W,
		matrix.Rows[2].X * this->X + matrix.Rows[2].Y * this->Y + matrix.Rows[2].Z * this->Z + matrix.Rows[2].W * this->W,
		matrix.Rows[3].X * this->X + matrix.Rows[3].Y * this->Y + matrix.Rows[3].Z * this->Z + matrix.Rows[3].W * this->W
	);
}

float Vector4f::Dot(const Vector4f& vector)
{
	return (this->X * vector.X) + (this->Y * vector.Y) + (this->Z * vector.Z) + (this->W * vector.W);
}

bool Vector4f::operator==(const Vector4f& right) const
{
	return (X == right.X && Y == right.Y && Z == right.Z && W == right.W);
}

bool Vector4f::operator!=(const Vector4f& right) const
{
	return !(*this == right);
}

// String Operations
std::string Vector4f::ToString() const
{
	return "(" + std::to_string(this->X) + ", " + std::to_string(this->Y) + ", " + std::to_string(this->Z) + ", " + std::to_string(this->W) + ")";
}

std::ostream& operator<<(std::ostream& stream, const Vector4f& right)
{
	return (stream << right.ToString());
}