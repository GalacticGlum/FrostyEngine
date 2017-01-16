#include <Math/Quaternion.h>
#include <Math/Vector3f.h>
#include <Math/Matrix4f.h>

const Quaternion Quaternion::Identity = Quaternion(0, 0, 0, 1);

Quaternion::Quaternion(const Vector3f& axis, float angle)
{
	this->SetXYZ(axis);
	this->W = angle;
}

Quaternion::Quaternion(const Vector4f& vector)
{
	this->X = vector.X;
	this->Y = vector.Y;
	this->Z = vector.Z;
	this->W = vector.W;
}

Quaternion& Quaternion::operator=(const Quaternion& quaternion)
{
	this->X = quaternion.X;
	this->Y = quaternion.Y;
	this->Z = quaternion.Z;
	this->W = quaternion.W;

	return *this;
}

Quaternion& Quaternion::Add(const Quaternion& right)
{
	this->X += right.X;
	this->Y += right.Y;
	this->Z += right.Z;
	this->W += right.W;

	return *this;
}

Quaternion& Quaternion::Subtract(const Quaternion& right)
{
	this->X -= right.X;
	this->Y -= right.Y;
	this->Z -= right.Z;
	this->W -= right.W;

	return *this;
}

Quaternion& Quaternion::Multiply(const Quaternion& right)
{
	this->X *= right.X;
	this->Y *= right.Y;
	this->Z *= right.Z;
	this->W *= right.W;

	return *this;
}

Quaternion& Quaternion::Divide(const Quaternion& right)
{
	this->X /= right.X;
	this->Y /= right.Y;
	this->Z /= right.Z;
	this->W /= right.W;

	return *this;
}

Quaternion& Quaternion::Multiply(const Vector3f& right)
{
	this->X = this->W * right.X + this->Y * right.Z - this->Z * right.Y;
	this->Y = this->W * right.Y + this->Z * right.X - this->X * right.Z;
	this->Z = this->W * right.Z + this->X * right.Y - this->Y * right.X;
	this->W = -this->X * right.X - this->Y * right.Y - this->Z * right.Z;

	return *this;
}

Quaternion& Quaternion::Add(float right)
{
	this->X += right;
	this->Y += right;
	this->Z += right;
	this->W += right;

	return *this;
}

Quaternion& Quaternion::Subtract(float right)
{
	this->X -= right;
	this->Y -= right;
	this->Z -= right;
	this->W -= right;

	return *this;
}

Quaternion& Quaternion::Multiply(float right)
{
	this->X *= right;
	this->Y *= right;
	this->Z *= right;
	this->W *= right;

	return *this;
}

Quaternion& Quaternion::Divide(float right)
{
	this->X /= right;
	this->Y /= right;
	this->Z /= right;
	this->W /= right;

	return *this;
}

float Quaternion::Magnitude() const
{
	return std::sqrtf(this->SquareMagnitude());
}

float Quaternion::SquareMagnitude() const
{
	return (this->X * this->X + this->Y * this->Y + this->Z * this->Z + this->W * this->W);
}

Quaternion& Quaternion::Normalize()
{
	float magnitude = this->Magnitude();
	
	this->X /= magnitude;
	this->Y /= magnitude;
	this->Z /= magnitude;
	this->W /= magnitude;

	return *this;
}

Quaternion Quaternion::Normalized() const
{
	float length = Magnitude();
	return Quaternion(this->X / length, this->Y / length, this->Z / length, this->W / length);
}

Quaternion Quaternion::Negative() const
{
	return Vector4f(-this->X, -this->Y, -this->Z, -this->W);
}

Quaternion& Quaternion::Negate()
{
	this->X = -this->X;
	this->Y = -this->Y;
	this->Z = -this->Z;
	this->W = -this->W;

	return *this;
}

const Vector3f Quaternion::GetXYZ() const
{
	return Vector3f(this->X, this->Y, this->Z);
}

Quaternion& Quaternion::SetXYZ(const Vector3f& vector)
{
	this->X = vector.X;
	this->Y = vector.Y;
	this->Z = vector.Z;

	return *this;
}

float Quaternion::GetElement(int32_t idx) const
{
	assert((idx >= 0 && idx <= 3) && "Quaternion::SetElement: int32_t 'idx' is out of range. (0 - 3)");

	return *(&this->X + idx);
}

Quaternion& Quaternion::SetElement(int32_t idx, float value)
{
	assert((idx >= 0 && idx <= 3) && "Quaternion::SetElement: int32_t 'idx' is out of range. (0, 3)");

	*(&this->X + idx) = value;
	return *this;
}

Vector3f Quaternion::GetAxis() const
{
	float x = 1.0f - this->W * this->W;

	// Check so we don't divide by zero!
	if (x < FrostyMath::Epsilon)
	{
		return Vector3f::XAxis;
	}

	return GetXYZ() / (x * x);
}

Vector3f Quaternion::ToEulerAngles() const
{
	float x1 = 2 * this->X * this->W - 2 * this->Y * this->Z;
	float x2 = 1 - 2 * this->X * this->X - 2 * this->Z * this->Z;

	float y1 = 2 * this->Y * this->W - 2 * this->X * this->Z;
	float y2 = 1 - 2 * this->Y * this->Y - 2 * this->Z * this->Z;

	float z = 2 * this->X * this->Y + 2 * this->Z * this->W;

	return Vector3f(std::atan2f(x1, x2), std::atan2f(y1, y2), std::asinhf(z));
}

float Quaternion::Dot(const Quaternion& quaternion) const
{
	float result = (this->X * quaternion.X);
	result += (this->Y * quaternion.Y);
	result += (this->Z * quaternion.Z);
	result += (this->W * quaternion.W);

	return result;
}

Quaternion Quaternion::Conjugate() const
{
	return Quaternion(-this->X, -this->Y, -this->Z, this->W);
}

Quaternion Quaternion::Lerp(const Quaternion& start, const Quaternion& destination, float blend, bool shortest)
{
	Quaternion correctedStart = start.Normalized();
	Quaternion correctDestination = destination;

	if (shortest && start.Dot(destination) < 0)
	{
		correctDestination = destination.Negative();
	}

	return Quaternion(FrostyMath::Lerp(correctedStart.X, correctDestination.X, blend),
		              FrostyMath::Lerp(correctedStart.Y, correctDestination.Y, blend),
		              FrostyMath::Lerp(correctedStart.Z, correctDestination.Z, blend),
		              FrostyMath::Lerp(correctedStart.W, correctDestination.W, blend));
}

Quaternion Quaternion::Slerp(const Quaternion& start, const Quaternion& destination, float blend, bool shortest)
{
	float destinationDot = destination.Dot(destination);
	Quaternion correctDestination = destination;

	if (shortest && destinationDot < 0)
	{
		destinationDot = -destinationDot;
		correctDestination = destination.Negative();
	}

	if (std::abs(destinationDot) >= 1 - FrostyMath::Epsilon)
	{
		return Quaternion::Lerp(start, correctDestination, blend, false);
	}

	float sqrtDest = std::sqrtf(1.0f - destinationDot * destinationDot);
	float angle = std::atan2f(sqrtDest, destinationDot);
	float invertedDest = 1.0f / sqrtDest;

	float factor = std::sinf((1.0f - blend) * angle) * invertedDest;
	float destinationFactor = std::sinf(blend * angle) * invertedDest;

	return (start * factor) + (correctDestination * destinationFactor);
}

float Quaternion::operator[](int32_t idx)
{
	assert((idx >= 0 && idx <= 3) && "Quaternion::operator[]: int32_t 'idx' is out of range (0, 3)");

	return *(&this->X + idx);
}

bool Quaternion::operator==(const Quaternion& quaternion) const
{
	return (this->X == quaternion.X) &&
		(this->Y == quaternion.Y) &&
		(this->Z == quaternion.Z) &&
		(this->W == quaternion.W);
}

bool Quaternion::operator!=(const Quaternion& quaternion) const
{
	return !(*this == quaternion);
}

Quaternion Quaternion::FromEulerAngles(const Vector3f& angles)
{
	Quaternion pitch(Vector3f::XAxis, angles.X);
	Quaternion yaw(Vector3f::YAxis, angles.Y);
	Quaternion roll(Vector3f::ZAxis, angles.Z);

	return pitch * yaw * roll;
}

// String Operations
std::string Quaternion::ToString() const
{
	return "(" + std::to_string(this->X) + ", " + std::to_string(this->Y) + ", " + std::to_string(this->Z) + ", " + std::to_string(this->W) + ")";
}

std::ostream& operator<<(std::ostream& stream, const Quaternion& right)
{
	return (stream << right.ToString());
}