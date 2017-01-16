#include <Math/Rectangle.h>

// String Operations
std::string Rectangle::ToString() const
{
	return "Position: " + this->Position.ToString() + ", Size: " + this->Size.ToString() + ")";
}

std::ostream& operator<<(std::ostream& stream, const Rectangle& right)
{
	return (stream << right.ToString());
}