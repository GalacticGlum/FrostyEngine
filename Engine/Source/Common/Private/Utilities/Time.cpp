#include <Utilities/Time.h>

std::chrono::high_resolution_clock::time_point Time::m_Epoch = std::chrono::high_resolution_clock::now();

double Time::GetTime()
{
	std::chrono::high_resolution_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - m_Epoch).count() / 1000000000.0;
}