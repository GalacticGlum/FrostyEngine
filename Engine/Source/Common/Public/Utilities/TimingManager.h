#pragma once

#include <chrono>
#include <map>
#include <memory>

#include <System/Delegate.h>

struct TimingManager
{
	void RegisterDelayedDelegate(std::shared_ptr<Delegate> delegate, float delay);
};