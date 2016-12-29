#pragma once

#include <assert.h>

#ifndef FROSTY_STATIC_LIBRARY
#ifdef FROSTY_CORE_EXPORTS
#define FROSTY_CORE_API __declspec(dllexport)
#else
#define FROSTY_CORE_API __declspec(dllimport)
#endif
#else
#define FROSTY_CORE_API 
#endif

#include <GameEngine.h>
#include <GameInstance.h>