#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <FrostyCommon.h>

#include <FrostyMath.h>

struct Vector3f;
struct FROSTY_COMMON_API Vector2f
{
	float X, Y;

	inline Vector2f() : Vector2f(0.0f, 0.0f) { }
	inline explicit Vector2f(float scalar) : Vector2f(scalar, scalar) { }
	inline Vector2f(float x, float y) : X(x), Y(y) { }

	Vector2f(const Vector3f& vector);

	Vector2f& Add(const Vector2f& right);
	Vector2f& Subtract(const Vector2f& right);
	Vector2f& Multiply(const Vector2f& right);
	Vector2f& Divide(const Vector2f& right);

	Vector2f& Add(float right);
	Vector2f& Subtract(float right);
	Vector2f& Multiply(float right);
	Vector2f& Divide(float right);

	Vector2f& Normalize();

	Vector2f Negative() const;
	Vector2f& Negate();

	Vector2f& Rotate(float angle);
	Vector2f& Abs();

	float Magnitude() const;
	float SquareMagnitude() const;

	float Distance(const Vector2f& vector) const;
	float Dot(const Vector2f& vector) const;
	float Cross(const Vector2f& vector) const;
	float Max() const;

	static Vector2f Lerp(const Vector2f& start, Vector2f& destination, float blend);

	inline friend FROSTY_COMMON_API Vector2f operator+(Vector2f left, const Vector2f& right) { return left.Add(right); }
	inline friend FROSTY_COMMON_API Vector2f operator-(Vector2f left, const Vector2f& right) { return left.Subtract(right); }
	inline friend FROSTY_COMMON_API Vector2f operator*(Vector2f left, const Vector2f& right) { return left.Multiply(right); }
	inline friend FROSTY_COMMON_API Vector2f operator/(Vector2f left, const Vector2f& right) { return left.Divide(right); }

	inline friend FROSTY_COMMON_API Vector2f operator-(Vector2f left) { return left.Negative(); }

	inline friend FROSTY_COMMON_API Vector2f operator+(Vector2f left, float right) { return left.Add(right); }
	inline friend FROSTY_COMMON_API Vector2f operator-(Vector2f left, float right) { return left.Subtract(right); }
	inline friend FROSTY_COMMON_API Vector2f operator*(Vector2f left, float right) { return left.Multiply(right); }
	inline friend FROSTY_COMMON_API Vector2f operator/(Vector2f left, float right) { return left.Divide(right); }

	inline Vector2f& operator+=(const Vector2f& right) { return this->Add(right); }
	inline Vector2f& operator-=(const Vector2f& right) { return this->Subtract(right); }
	inline Vector2f& operator*=(const Vector2f& right) { return this->Multiply(right); }
	inline Vector2f& operator/=(const Vector2f& right) { return this->Divide(right); }

	inline Vector2f& operator+=(float right) { return this->Add(right); }
	inline Vector2f& operator-=(float right) { return this->Subtract(right); }
	inline Vector2f& operator*=(float right) { return this->Multiply(right); }
	inline Vector2f& operator/=(float right) { return this->Divide(right); }

	bool operator==(const Vector2f& right) const;
	bool operator!=(const Vector2f& right) const;

	bool operator<(const Vector2f& right) const;
	bool operator<=(const Vector2f& right) const;
	bool operator>(const Vector2f& right) const;
	bool operator>=(const Vector2f& right) const;

	std::string ToString() const;
	friend FROSTY_COMMON_API std::ostream& operator<<(std::ostream& stream, const Vector2f& right);

	static const Vector2f Zero;
	static const Vector2f One;
};