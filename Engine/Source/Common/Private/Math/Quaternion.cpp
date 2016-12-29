#include <Math/Quaternion.h>

#define ZERO_TOLERANCE 0.0000001f

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
	return std::sqrtf(this->X * this->X + this->Y * this->Y + this->Z * this->Z + this->W * this->W);
}

Quaternion Quaternion::Normalize() const
{
	const float magnitude = this->Magnitude();
	return Vector4f(this->X / Magnitude(), this->Y / magnitude, this->Z / magnitude, this->W / magnitude);
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
	assert((idx >= 0 && idx <= 3), ("Quaternion::GetElement: int32_t 'idx' is out of range (0, 3)"));

	return *(&this->X + idx);
}

Quaternion& Quaternion::SetElement(int32_t idx, float value)
{
	assert((idx >= 0 && idx <= 3), ("Quaternion::SetElement: int32_t 'idx' is out of range (0, 3)"));

	*(&this->X + idx) = value;
	return *this;
}

Vector3f Quaternion::GetAxis() const
{
	float x = 1.0f - this->W * this->W;

	// Check so we don't divide by zero!
	if (x < ZERO_TOLERANCE)
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

Matrix4f Quaternion::ToRotationMatrix() const
{
	Vector3f unitForward = Vector3f(2.0f * (this->X * this->Z - this->W * this->Y), 2.0f * (this->Y * this->Z + this->W * this->X), 1.0f - 2.0f * (this->X * this->X + this->Y * this->Y));
	Vector3f unitUp = Vector3f(2.0f * (this->X * this->Y + this->W * this->Z), 1.0f - 2.0f * (this->X * this->X + this->Z * this->Z), 2.0f * (this->X * this->Z - this->W * this->X));
	Vector3f unitRight = Vector3f(1.0f - 2.0f * (this->Y * this->Y + this->Z * this->Z), 2.0f * (this->X * this->Y - this->W * this->Z), 2.0f * (this->X * this->Z + this->W * this->Y));

	return Matrix4f::Rotate(unitForward, unitUp, unitRight);
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

float Quaternion::operator[](int32_t idx)
{
	assert((idx >= 0 && idx <= 3), ("Quaternion::operator[]: int32_t 'idx' is out of range (0, 3)"));

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

Vector3f Quaternion::Rotate(const Quaternion& quaternion, const Vector3f& axis)
{
	float rX;
	float rY;
	float rZ;
	float rW;

	rX = (((quaternion.W * axis.X) + (quaternion.Y * axis.Z)) - (quaternion.Z * axis.Y));
	rY = (((quaternion.W * axis.Y) + (quaternion.Z * axis.X)) - (quaternion.X * axis.Z));
	rZ = (((quaternion.W * axis.Z) + (quaternion.X * axis.Y)) - (quaternion.Y * axis.X));
	rW = (((quaternion.X * axis.X) + (quaternion.Y * axis.Y)) + (quaternion.Z * axis.Z));

	float fX = (((rW * quaternion.X) + (rX * quaternion.W)) - (rY * quaternion.Z)) + (rZ * quaternion.Y);
	float fY = (((rW * quaternion.Y) + (rY * quaternion.W)) - (rZ * quaternion.X)) + (rX * quaternion.Z);
	float fZ = (((rW * quaternion.Z) + (rZ * quaternion.W)) - (rX * quaternion.Y)) + (rY * quaternion.X);

	return Vector3f(fX, fY, fZ);
}

const Quaternion Quaternion::Rotation(const Vector3f& unitOne, const Vector3f& unitTwo)
{
	float halfCosine;
	float halfCosineReciprocal;

	halfCosine = std::sqrt((2.0f * (1.0f + unitOne.Dot(unitTwo))));
	halfCosineReciprocal = (1.0f / halfCosine);

	return Quaternion((unitOne.Cross(unitTwo) * halfCosineReciprocal), (halfCosine * 0.5f));
}

const Quaternion Quaternion::Rotation(float radians, const Vector3f& unit)
{
	float angle = radians * 0.5f;
	return Quaternion(unit * std::sin(angle), std::cos(angle));
}

const Quaternion Quaternion::RotationX(float radians)
{
	float angle = radians * 0.5f;
	return Quaternion(std::sin(angle), 0, 0, std::cos(angle));
}

const Quaternion Quaternion::RotationY(float radians)
{
	float angle = radians * 0.5f;
	return Quaternion(0, std::sin(angle), 0, std::cos(angle));
}

const Quaternion Quaternion::RotationZ(float radians)
{
	float angle = radians * 0.5f;
	return Quaternion(0, 0, std::sin(angle), std::cos(angle));
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