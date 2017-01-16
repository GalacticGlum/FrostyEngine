#include <Utilities/Random.h>

std::mt19937 Random::m_RandomEngine;
int Random::Range(int min, int max)
{
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(Random::m_RandomEngine);
}

long Random::Range(long min, long max)
{
	std::uniform_int_distribution<long> distribution(min, max);
	return distribution(Random::m_RandomEngine);
}

float Random::Range(float min, float max)
{
	std::uniform_real_distribution<float> distribution(min, max);
	return distribution(Random::m_RandomEngine);
}

double Random::Range(double min, double max)
{
	std::uniform_real_distribution<double> distribution(min, max);
	return distribution(Random::m_RandomEngine);
}

Vector2f Random::Vector2(const Vector2f& min, const Vector2f& max)
{
	std::uniform_real_distribution<float> distrubutionX(min.X, max.X);
	std::uniform_real_distribution<float> distrubutionY(min.Y, max.Y);

	return Vector2f(distrubutionX(Random::m_RandomEngine), distrubutionY(Random::m_RandomEngine));
}

Vector3f Random::Vector3(const Vector3f& min, const Vector3f& max)
{
	std::uniform_real_distribution<float> distrubutionX(min.X, max.X);
	std::uniform_real_distribution<float> distrubutionY(min.Y, max.Y);
	std::uniform_real_distribution<float> distrubutionZ(min.Z, max.Z);

	return Vector3f(distrubutionX(Random::m_RandomEngine), distrubutionY(Random::m_RandomEngine), distrubutionZ(Random::m_RandomEngine));
}

Vector4f Random::Vector4(const Vector4f& min, const Vector4f& max)
{
	std::uniform_real_distribution<float> distrubutionX(min.X, max.X);
	std::uniform_real_distribution<float> distrubutionY(min.Y, max.Y);
	std::uniform_real_distribution<float> distrubutionZ(min.Z, max.Z);
	std::uniform_real_distribution<float> distrubutionW(min.W, max.W);

	return Vector4f(distrubutionX(Random::m_RandomEngine), distrubutionY(Random::m_RandomEngine), distrubutionZ(Random::m_RandomEngine), distrubutionW(Random::m_RandomEngine));
}

Colour Random::RGB()
{
	std::uniform_int_distribution<int> distrubutionR(0, 255);
	std::uniform_int_distribution<int> distrubutionG(0, 255);
	std::uniform_int_distribution<int> distrubutionB(0, 255);

	return Colour(distrubutionR(Random::m_RandomEngine), distrubutionG(Random::m_RandomEngine), distrubutionB(Random::m_RandomEngine), 255);
}

Colour Random::RGBA()
{
	std::uniform_int_distribution<int> distrubutionR(0, 255);
	std::uniform_int_distribution<int> distrubutionG(0, 255);
	std::uniform_int_distribution<int> distrubutionB(0, 255);
	std::uniform_int_distribution<int> distrubutionA(0, 255);

	return Colour(distrubutionR(Random::m_RandomEngine), distrubutionG(Random::m_RandomEngine), distrubutionB(Random::m_RandomEngine), distrubutionA(Random::m_RandomEngine));
}
