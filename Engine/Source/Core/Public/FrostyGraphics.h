#pragma once

#ifdef FROSTY_STATIC_LIBRARY
#define GLEW_STATIC
#endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Colour.h>

#include <Graphics/RenderingSubsystem.h>
#include <Graphics/Window.h>
#include <Graphics/Vertex.h>
#include <Graphics/Mesh.h>
#include <Graphics/Texture.h>
#include <Graphics/Shader.h>
#include <Graphics/Transform.h>
#include <Graphics/Camera.h>
