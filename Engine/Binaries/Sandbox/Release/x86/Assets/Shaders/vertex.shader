#version 330

layout (location = 0) in vec3 position;
out vec4 outColour;
uniform mat4 mvpMatrix;

void main()
{
    outColour = vec4(clamp(position, 0.0, 1.0), 1.0);
    gl_Position = mvpMatrix * vec4(position, 1.0);
}