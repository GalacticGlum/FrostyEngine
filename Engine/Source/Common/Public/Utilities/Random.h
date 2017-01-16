#pragma once

#include <string>
#include <random>

#include <FrostyCommon.h>
#include <FrostyMath.h>
#include <FrostyGraphics.h>

#include <Utilities/String.h>

class FROSTY_COMMON_API Random
{
public:
	inline static void Initialize() { Random::Initialize(static_cast<int>(Time::GetTime() * 1000)); }
	inline static void Initialize(const std::string& seed) { Random::Initialize(String::GetHash(seed)); }
	inline static void Initialize(unsigned int seed) { Random::m_RandomEngine = std::mt19937(seed); }

	static int Range(int min, int max);
	static long Range(long min, long max);
	static float Range(float min, float max);
	static double Range(double min, double max);

	inline static float Value() { return Range(0.0f, 1.0f); }

	inline static Vector2f Vector2() { return Random::Vector2(0, FrostyMath::MaxFloat); }
	inline static Vector2f Vector2(float min, float max) { return Random::Vector2(Vector2f(min), Vector2f(max)); }
	inline static Vector2f Vector2(float minX, float maxX, float minY, float maxY) { return Random::Vector2(Vector2f(minX, minY), Vector2f(maxX, maxY)); }
	static Vector2f Vector2(const Vector2f& min, const Vector2f& max);

	inline static Vector3f Vector3() { return Random::Vector3(0, FrostyMath::MaxFloat); }
	inline static Vector3f Vector3(float min, float max) { return Random::Vector3(Vector3f(min), Vector3f(max)); }
	inline static Vector3f Vector3(float minX, float maxX, float minY, float maxY, float minZ, float maxZ) { return Random::Vector3(Vector3f(minX, minY, minZ), Vector3f(maxX, maxY, maxZ)); }
	static Vector3f Vector3(const Vector3f& min, const Vector3f& max);

	inline static Vector4f Vector4() { return Random::Vector4(0, FrostyMath::MaxFloat); }
	inline static Vector4f Vector4(float min, float max) { return Random::Vector4(Vector4f(min), Vector4f(max)); }
	inline static Vector4f Vector4(float minX, float maxX, float minY, float maxY, float minZ, float maxZ, float minW, float maxW) { return Random::Vector4(Vector4f(minX, minY, minZ, minW), Vector4f(maxX, maxY, maxZ, maxW)); }
	static Vector4f Vector4(const Vector4f& min, const Vector4f& max);

	static Colour RGB();
	static Colour RGBA();

private:
	static std::mt19937 m_RandomEngine;
};