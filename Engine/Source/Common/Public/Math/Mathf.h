#pragma once

#include <iostream>
#include <cmath>

static const double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930382;
static const double PI_OVER_2 = PI / 2;
static const double PI_OVER_3 = PI / 3;
static const double PI_OVER_4 = PI / 4;
static const double PI_OVER_6 = PI / 6;
static const double TWO_PI = 2 * PI;
static const double THREE_PI_OVER_2 = 3 * PI / 2;

static const double E = 2.71828182845904523536;
static const double LOG_10E = 0.434294482;
static const double LOG_2E = 1.442695041;

struct Mathf
{
	// Next Power of Two
	static long NextPowerOfTwo(long n)
	{
		if (n < 0)
		{
			// TODO: Logging system
			std::cerr << "Mathf::NextPowerOfTwo: long 'n' must be positive!\n";
			exit(1);
		}

		return static_cast<long>(std::pow(2, std::ceil(std::log2(static_cast<double>(n)))));
	}

	static int NextPowerOfTwo(int n)
	{
		if (n < 0)
		{
			// TODO: Logging system
			std::cerr << "Mathf::NextPowerOfTwo: int 'n' must be positive!\n";
			exit(1);
		}

		return static_cast<int>(std::pow(2, std::ceil(std::log2(static_cast<double>(n)))));
	}

	static float NextPowerOfTwo(float n)
	{
		if (n < 0)
		{
			// TODO: Logging system
			std::cerr << "Mathf::NextPowerOfTwo: float 'n' must be positive!\n";
			exit(1);
		}

		return static_cast<float>(std::pow(2, std::ceil(std::log2(static_cast<double>(n)))));
	}

	static double NextPowerOfTwo(double n)
	{
		if (n < 0)
		{
			// TODO: Logging system
			std::cerr << "Mathf::NextPowerOfTwo: double 'n' must be positive!\n";
			exit(1);
		}

		return static_cast<double>(std::pow(2, std::ceil(std::log2(static_cast<double>(n)))));
	}

	// Factorial
	static long Factorial(int n)
	{
		long result = 1;

		for (; n > 1; n--)
		{
			result *= n;
		}

		return result;
	}

	// Binomial Coefficient
	static long BinomialCoefficient(int n, int k)
	{
		return Factorial(n) / (Factorial(k) * Factorial(n - k));
	}

	// Inverse Square Root FAST
	static float InverseSqrtFast(float x)
	{
		float halfX = 0.5f * x;
		int i = *(int*)&x;              
		i = 0x5f375a86 - (i >> 1);      
		x = *(float*)&i;                
		x = x * (1.5f - halfX * x * x); 
		return x;
	}

	static double InverseSqrtFast(double x)
	{
		return InverseSqrtFast(static_cast<float>(x));
	}

	// Degree/Radian Conversion
	static float DegreesToRadians(float degrees)
	{
		const float degreeToRadian = static_cast<float>(PI / 180.0f);
		return degrees * degreeToRadian;
	}

	static float RadiansToDegrees(float radians)
	{
		const float radianToDegree = 180.0f / static_cast<float>(PI);
		return radians * radianToDegree;
	}

	static double DegreesToRadians(double degrees)
	{
		const double degreeToRadian = PI / 180.0;
		return degrees * degreeToRadian;
	}

	static double RadiansToDegree(double radians)
	{
		const double radianToDegree = 180.0 / PI;
		return radians * radianToDegree;
	}

	// Swap
	static void Swap(double& a, double& b)
	{
		double temp = a;
		a = b;
		b = temp;
	}

	static void Swap(float& a, float& b)
	{
		float temp = a;
		a = b;
		b = temp;
	}
};