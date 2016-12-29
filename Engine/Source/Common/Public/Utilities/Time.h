#pragma once
#pragma warning (disable : 4251)

#include <FrostyCommon.h>
#include <time.h>
#include <chrono>

class FROSTY_COMMON_API Time
{
public:
	static double GetTime();

	static const double SECOND;
	inline static double GetDeltaTime() { return m_DeltaTime; }
	inline static void SetDeltaTime(double deltaTime) { m_DeltaTime = deltaTime; }
private:
	static std::chrono::high_resolution_clock::time_point m_Epoch;
	static double m_DeltaTime;

};