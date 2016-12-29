#pragma once

#ifdef FROSTY_STATIC_LIBRARY
#define GLEW_STATIC
#else
#define GLEW_BUILD
#endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Graphics/Window.h>