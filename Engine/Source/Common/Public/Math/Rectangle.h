#pragma once

#include <iostream>
#include <string>

#include <FrostyCommon.h>
#include <Math/Vector2f.h>

struct FROSTY_COMMON_API Rectangle
{
	Vector2f Position;
	Vector2f Size;
	
	inline Rectangle() : Rectangle(Vector2f::Zero, Vector2f::One) {}
	inline Rectangle(float x, float y, float width, float height) : Rectangle(Vector2f(x, y), Vector2f(width, height)) {}
	inline Rectangle(const Vector2f& position, const Vector2f& size) : Position(position), Size(size) {}

	inline bool Contains(const Vector2f& point) const { return point > this->GetInnerBounds() && point < this->GetOuterBounds(); }
	inline bool Contains(const Vector3f& point) const { return this->Contains(Vector2f(point)); }
	inline bool Contains(const Vector4f& point) const { return this->Contains(Vector2f(point)); }

	inline bool Intersects(const Rectangle& rectangle) const  { return (this->Size > rectangle.Position && this->Position < rectangle.Size) || (this->Position > rectangle.Size && this->Size < rectangle.Position); }

	inline Vector2f GetInnerBounds() const { return this->Position - this->Size; }
	inline Vector2f GetOuterBounds() const { return this->Position + this->Size; }

	inline bool operator==(const Rectangle& right) const { return this->Position == right.Position && this->Size == right.Size; }
	inline bool operator!=(const Rectangle& right) const { return this->Position != right.Position && this->Size != right.Size; }

	inline bool operator<(const Rectangle& right) const { return this->Size < right.Size; }
	inline bool operator>(const Rectangle& right) const { return this->Size > right.Size; }

	std::string ToString() const;
	friend FROSTY_COMMON_API std::ostream& operator<<(std::ostream& stream, const Rectangle& right);
};