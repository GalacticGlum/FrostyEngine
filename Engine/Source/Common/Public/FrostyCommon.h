#pragma once

#include <assert.h>

#ifndef FROSTY_STATIC_LIBRARY
#ifdef FROSTY_COMMON_EXPORTS
#define FROSTY_COMMON_API __declspec(dllexport)
#else
#define FROSTY_COMMON_API __declspec(dllimport)
#endif
#else
#define FROSTY_COMMON_API 
#endif

#include <Utilities/Time.h>