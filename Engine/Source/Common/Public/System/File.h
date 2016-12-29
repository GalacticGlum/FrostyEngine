#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <FrostyCommon.h>

class FROSTY_COMMON_API File
{
public:
	static std::string Read(const std::string& filePath);
	static bool Write(const std::string& filePath, const std::string& content);
	static bool Exists(const std::string& filePath);
};