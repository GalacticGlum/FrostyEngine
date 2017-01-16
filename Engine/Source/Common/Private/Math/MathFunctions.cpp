#include <Math/MathFunctions.h>
#include <FrostyMath.h>

const float FrostyMath::Epsilon = std::numeric_limits<float>::epsilon();

const long FrostyMath::MaxLong = std::numeric_limits<long>::max();
const int FrostyMath::MaxInt = std::numeric_limits<int>::max();
const float FrostyMath::MaxFloat = std::numeric_limits<float>::max();
const double FrostyMath::MaxDouble = std::numeric_limits<double>::max();

long FrostyMath::NextPowerOfTwo(long n)
{
	if (n < 0)
	{
		// TODO: Logging system
		std::cerr << "FrostyMath::NextPowerOfTwo: long 'n' must be positive!\n";
		exit(1);
	}

	return static_cast<long>(std::pow(2, std::ceil(std::log2(static_cast<double>(n)))));
}

int FrostyMath::NextPowerOfTwo(int n)
{
	if (n < 0)
	{
		// TODO: Logging system
		std::cerr << "FrostyMath::NextPowerOfTwo: int 'n' must be positive!\n";
		exit(1);
	}

	return static_cast<int>(std::pow(2, std::ceil(std::log2(static_cast<double>(n)))));
}

float FrostyMath::NextPowerOfTwo(float n)
{
	if (n < 0)
	{
		// TODO: Logging system
		std::cerr << "FrostyMath::NextPowerOfTwo: float 'n' must be positive!\n";
		exit(1);
	}

	return static_cast<float>(std::pow(2, std::ceil(std::log2(static_cast<double>(n)))));
}

double FrostyMath::NextPowerOfTwo(double n)
{
	if (n < 0)
	{
		// TODO: Logging system
		std::cerr << "FrostyMath::NextPowerOfTwo: double 'n' must be positive!\n";
		exit(1);
	}

	return static_cast<double>(std::pow(2, std::ceil(std::log2(static_cast<double>(n)))));
}

long FrostyMath::Factorial(int n)
{
	long result = 1;

	for (; n > 1; n--)
	{
		result *= n;
	}

	return result;
}

long FrostyMath::BinomialCoefficient(int n, int k)
{
	return Factorial(n) / (Factorial(k) * Factorial(n - k));
}

float FrostyMath::InverseSqrtFast(float x)
{
	float halfX = 0.5f * x;
	int i = *(int*)&x;
	i = 0x5f375a86 - (i >> 1);
	x = *(float*)&i;
	x = x * (1.5f - halfX * x * x);
	return x;
}

float FrostyMath::DegreesToRadians(float degrees)
{
	const float degreeToRadian = static_cast<float>(PI / 180.0f);
	return degrees * degreeToRadian;
}

float FrostyMath::RadiansToDegrees(float radians)
{
	const float radianToDegree = 180.0f / static_cast<float>(PI);
	return radians * radianToDegree;
}

double FrostyMath::DegreesToRadians(double degrees)
{
	const double degreeToRadian = PI / 180.0;
	return degrees * degreeToRadian;
}

double FrostyMath::RadiansToDegree(double radians)
{
	const double radianToDegree = 180.0 / PI;
	return radians * radianToDegree;
}

void FrostyMath::Swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

void FrostyMath::Swap(float& a, float& b)
{
	float temp = a;
	a = b;
	b = temp;
}

bool FrostyMath::IsEqualApproximate(const Vector2f& left, const Vector2f& right)
{
	return IsEqualApproximate(left.X, right.X) && 
		   IsEqualApproximate(left.Y, right.Y);
}

bool FrostyMath::IsEqualApproximate(const Vector3f& left, const Vector3f& right)
{
	return IsEqualApproximate(left.X, right.X) && 
		   IsEqualApproximate(left.Y, right.Y) && 
		   IsEqualApproximate(left.Z, right.Z);
}

bool FrostyMath::IsEqualApproximate(const Vector4f& left, const Vector4f& right)
{
	return IsEqualApproximate(left.X, right.X) && 
		   IsEqualApproximate(left.Y, right.Y) && 
		   IsEqualApproximate(left.Z, right.Z) && 
		   IsEqualApproximate(left.W, right.W);
}


