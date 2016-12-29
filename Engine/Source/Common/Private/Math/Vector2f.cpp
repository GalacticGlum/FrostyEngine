#include <Math/Vector2f.h>

const Vector2f Vector2f::Zero = Vector2f(0, 0);
const Vector2f Vector2f::One = Vector2f(1, 1);

Vector2f::Vector2f(const Vector3f& vector) : Vector2f(vector.X, vector.Y) 
{
}

Vector2f& Vector2f::Add(const Vector2f& right)
{
	this->X += right.X;
	this->Y += right.Y;

	return (*this);
}

Vector2f& Vector2f::Subtract(const Vector2f& right)
{
	this->X -= right.X;
	this->Y -= right.Y;

	return (*this);
}

Vector2f& Vector2f::Multiply(const Vector2f& right)
{
	this->X *= right.X;
	this->Y *= right.Y;

	return (*this);
}

Vector2f& Vector2f::Divide(const Vector2f& right)
{
	this->X /= right.X;
	this->Y /= right.Y;

	return (*this);
}

Vector2f& Vector2f::Add(float right)
{
	this->X += right;
	this->Y += right;

	return (*this);
}

Vector2f& Vector2f::Subtract(float right)
{
	this->X -= right;
	this->Y -= right;

	return (*this);
}

Vector2f& Vector2f::Multiply(float right)
{
	this->X *= right;
	this->Y *= right;

	return (*this);
}

Vector2f& Vector2f::Divide(float right)
{
	this->X /= right;
	this->Y /= right;

	return (*this);
}

Vector2f Vector2f::Normalize() const
{
	float length = Magnitude();
	return Vector2f(this->X / length, this->Y / length);
}

Vector2f& Vector2f::Rotate(float angle)
{
	double radian = Mathf::DegreesToRadians(angle);
	double cosine = std::cos(radian);
	double sine = std::sin(radian);

	this->X = static_cast<float>(this->X * cosine - this->Y * sine);
	this->Y = static_cast<float>(this->X * sine + this->Y * cosine);

	return *this;
}

Vector2f& Vector2f::Abs()
{
	this->X = std::abs(this->X);
	this->Y = std::abs(this->Y);

	return *this;
}

Vector2f& Vector2f::Lerp(const Vector2f& destination, float time)
{
	Vector2f result = (destination - (*this) * time + (*this));
	this->X = result.X;
	this->Y = result.Y;

	return *this;
}

float Vector2f::Magnitude() const 
{
	return sqrt(SquareMagnitude());
}

float Vector2f::SquareMagnitude() const
{
	return (this->X * this->X) + (this->Y * this->Y);
}

float Vector2f::Distance(const Vector2f& vector) const
{
	float a = this->X - vector.X;
	float b = this->Y - vector.Y;

	return sqrt((a * a) + (b * b));
}

float Vector2f::Dot(const Vector2f& vector) const
{
	return (this->X * vector.X) + (this->Y * vector.Y);
}

float Vector2f::Cross(const Vector2f& vector) const
{
	return this->X * vector.Y - this->Y * vector.X;
}

float Vector2f::Max() const
{
	return std::max(this->X, this->Y);
}

// Comparitive Operators
bool Vector2f::operator==(const Vector2f& right) const 
{
	return (X == right.X && Y == right.Y);
}

bool Vector2f::operator!=(const Vector2f& right) const
{
	return !(*this == right);
}

bool Vector2f::operator<(const Vector2f& right) const 
{
	return (X < right.X && Y < right.Y);
}

bool Vector2f::operator<=(const Vector2f& right) const
{
	return (X <= right.X && Y <= right.Y);
}

bool Vector2f::operator>(const Vector2f& right) const
{
	return (X > right.X && Y > right.Y);
}

bool Vector2f::operator>=(const Vector2f& right) const
{
	return (X >= right.X && Y >= right.Y);
}

// String Operations
std::string Vector2f::ToString() const
{
	return "(" + std::to_string(this->X) + ", " + std::to_string(this->Y) + ")";
}

std::ostream& operator<<(std::ostream& stream, const Vector2f& right)
{
	return (stream << right.ToString());
}
