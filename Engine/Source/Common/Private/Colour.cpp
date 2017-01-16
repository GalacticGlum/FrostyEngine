#include <Colour.h>
#include <FrostyMath.h>

const Colour Colour::White = Colour(255);
const Colour Colour::Black = Colour(0, 255);

Colour::Colour(const Vector3f& vector) : 
	R(static_cast<int>(vector.X)), 
	G(static_cast<int>(vector.Y)), 
	B(static_cast<int>(vector.Z)), 
	A(1) {}

Colour::Colour(const Vector4f& vector) : 
	R(static_cast<int>(vector.X)), 
	G(static_cast<int>(vector.Y)), 
	B(static_cast<int>(vector.Z)), 
	A(static_cast<int>(vector.W)) {}

// Comparative Operators
bool Colour::operator==(const Colour& right) const
{
	return (this->R == right.R && this->G == right.G && this->B == right.B && this->A == right.A);
}

bool Colour::operator!=(const Colour& right) const
{
	return !(*this == right);
}

bool Colour::operator<(const Colour& right) const
{
	return  (this->R < right.R && this->G < right.G && this->B < right.B && this->A < right.A);
}

bool Colour::operator<=(const Colour& right) const
{
	return  (this->R <= right.R && this->G <= right.G && this->B <= right.B && this->A <= right.A);
}

bool Colour::operator>(const Colour& right) const
{
	return (this->R > right.R && this->G > right.G && this->B > right.B && this->A > right.A);
}

bool Colour::operator>=(const Colour& right) const
{
	return (this->R >= right.R && this->G >= right.G && this->B >= right.B && this->A >= right.A);
}

Colour Colour::Lerp(const Colour& start, const Colour& destination, float blend)
{
	return Colour(FrostyMath::Lerp(start.R, destination.R, blend), 
		          FrostyMath::Lerp(start.G, destination.G, blend), 
		          FrostyMath::Lerp(start.B, destination.B, blend), 
		          FrostyMath::Lerp(start.A, destination.A, blend));
}
