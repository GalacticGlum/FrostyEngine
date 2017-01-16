#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cassert>

#include <FrostyCommon.h>
#include <FrostyMath.h>

struct Vector3f;
struct Matrix4f;
struct FROSTY_COMMON_API Quaternion
{
	float X, Y, Z, W;

	inline Quaternion() : Quaternion(0, 0, 0, 1) { }
	inline explicit Quaternion(float scalar) : Quaternion(scalar, scalar, scalar, scalar) { }
	inline Quaternion(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w) { }
	inline Quaternion(const Quaternion& quaternion) : X(quaternion.X), Y(quaternion.Y), Z(quaternion.Z), W(quaternion.W) { }

	Quaternion(const Vector3f& axis, float angle);
	Quaternion(const Vector4f& vector);
	// TODO: Quaternion(const Matrix4f rotation);

	Quaternion& Add(const Quaternion& right);
	Quaternion& Subtract(const Quaternion& right);
	Quaternion& Multiply(const Quaternion& right);
	Quaternion& Divide(const Quaternion& right);

	Quaternion& Add(float right);
	Quaternion& Subtract(float right);
	Quaternion& Multiply(float right);
	Quaternion& Divide(float right);

	Quaternion& Multiply(const Vector3f& right);

	float Magnitude() const;
	float SquareMagnitude() const;

	Quaternion& Normalize();
	Quaternion Normalized() const;

	Quaternion Negative() const;
	Quaternion& Negate();

	const Vector3f GetXYZ() const;
	Quaternion& SetXYZ(const Vector3f& vector);

	float GetElement(int32_t idx) const;
	Quaternion& SetElement(int32_t idx, float value);

	Vector3f GetAxis() const;
	Vector3f ToEulerAngles() const;

	float Dot(const Quaternion& quaternion) const;
	Quaternion Conjugate() const;

	Quaternion& operator=(const Quaternion& quaternion);

	inline friend FROSTY_COMMON_API const Quaternion operator+(Quaternion left, const Quaternion& right) { return left.Add(right); }
	inline friend FROSTY_COMMON_API const Quaternion operator-(Quaternion left, const Quaternion& right) { return left.Subtract(right); }
	inline friend FROSTY_COMMON_API const Quaternion operator*(Quaternion left, const Quaternion& right) { return left.Multiply(right); }
	inline friend FROSTY_COMMON_API const Quaternion operator*(Quaternion left, const Vector3f& right) { return left.Multiply(right); }

	inline friend FROSTY_COMMON_API const Quaternion operator*(Quaternion left, float scalar) { return left.Multiply(scalar); }
	inline friend FROSTY_COMMON_API const Quaternion operator/(Quaternion left, float scalar) { return left.Divide(scalar); }

	float operator[](int32_t idx);

	inline Quaternion& operator+=(const Quaternion& right) { return this->Add(right); }
	inline Quaternion& operator-=(const Quaternion& right) { return this->Subtract(right); }
	inline Quaternion& operator*=(const Quaternion& right) { return this->Multiply(right); }

	inline Quaternion& operator*=(float scalar) { return this->Multiply(scalar); }
	inline Quaternion& operator/=(float scalar) { return this->Divide(scalar); }

	bool operator==(const Quaternion& quaternion) const;
	bool operator!=(const Quaternion& quaternion) const;

	static Quaternion FromEulerAngles(const Vector3f& angles);

	static Quaternion Lerp(const Quaternion& start, const Quaternion& destination, float blend, bool shortest);
	static Quaternion Slerp(const Quaternion& start, const Quaternion& destination, float blend, bool shortest);

	std::string ToString() const;
	friend FROSTY_COMMON_API std::ostream& operator<<(std::ostream& stream, const Quaternion& right);

	static const Quaternion Identity;
};