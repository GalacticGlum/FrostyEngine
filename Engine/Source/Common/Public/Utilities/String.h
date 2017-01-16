#pragma once

#include <unordered_map>
#include <string>
#include <FrostyCommon.h>

class FROSTY_COMMON_API String
{
public:
	inline static int GetHash(const std::string& hashString) { return static_cast<int>(String::m_Hasher(hashString)); }
private:
	static const std::hash<std::string> m_Hasher;
};