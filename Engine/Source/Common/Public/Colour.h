#pragma once

#include <FrostyCommon.h>

struct Vector3f;
struct Vector4f;
struct FROSTY_COMMON_API Colour
{
	int R, G, B, A;

	inline Colour() : Colour(0, 255) {}
	inline explicit Colour(int rgba) : Colour(rgba, rgba, rgba, rgba) {}
	inline Colour(int rgb, int a) : Colour(rgb, rgb, rgb, a) {}
	inline Colour(int r, int g, int b) : Colour(r, g, b, 255) {}
	inline Colour(int r, int g, int b, int a) : R(r), G(g), B(b), A(a) {}

	Colour(const Vector3f& vector);
	Colour(const Vector4f& vector);

	bool operator==(const Colour& right) const;
	bool operator!=(const Colour& right) const;

	bool operator<(const Colour& right) const;
	bool operator<=(const Colour& right) const;
	bool operator>(const Colour& right) const;
	bool operator>=(const Colour& right) const;

	static Colour Lerp(const Colour& start, const Colour& destination, float blend);

	static const Colour White;
	static const Colour Black;
};