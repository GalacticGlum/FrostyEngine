#include <Graphics/RenderingSubsystem.h>

void RenderingSubsystem::Initialize()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DEPTH_CLAMP);

	glEnable(GL_TEXTURE_2D);
}