#pragma once

#include <time.h>
#include <chrono>

#include <FrostyCommon.h>

class FROSTY_COMMON_API Time
{
public:
	static double GetTime();
private:
	static std::chrono::high_resolution_clock::time_point m_Epoch;
};