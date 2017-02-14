#pragma once

#include <functional>
#include <map>

template<typename... TArgs>
class Delegate
{
public:
	Delegate() : currentHandle(0) { }
	Delegate(const Delegate& other) : currentHandle(0) { }

	template<typename TFunction, typename... TFArgs>
	inline int Connect(TFunction&& function, TFArgs&&... args)
	{
		this->m_Functions.insert({ ++this->currentHandle, std::bind(function, args...) });
		return this->currentHandle;
	}

	inline int Connect(const std::function<void(TArgs...)>& function)
	{
		this->m_Functions.insert({ ++this->currentHandle, function });
		return this->currentHandle;
	}

	inline void Disconnect(int handle) { this->m_Functions.erase(handle); }
	inline void DisconnectAll() { this->m_Functions.clear(); }

	inline void Execute(TArgs... args) const
	{
		for (auto function : this->m_Functions)
		{
			function.second(args...);
		}
	}

	Delegate& operator=(const Delegate& other) 
	{ 
		this->DisconnectAll();
		return (*this);
	}

private:
	std::map<int, std::function<void(TArgs...)>> m_Functions;
	int currentHandle;
};