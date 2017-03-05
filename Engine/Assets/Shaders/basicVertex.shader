#version 450

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 textureCoordinate;

out vec2 uvCoordinate;
uniform mat4 mvpMatrix;

void main()
{
    gl_Position = mvpMatrix * vec4(position, 1.0);
    uvCoordinate = textureCoordinate;
}