#pragma once

#include <FrostyCommon.h>
#include <time.h>
#include <chrono>

class FROSTY_COMMON_API Time
{
public:
	static double GetTime();
	static const double SECOND;
private:
	static std::chrono::high_resolution_clock::time_point m_Epoch;
};