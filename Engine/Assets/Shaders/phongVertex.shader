#version 450

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 textureCoordinate;
layout (location = 2) in vec3 normal;

out vec2 uvCoordinate;
out vec3 normals;

uniform mat4 mvpMatrix;
uniform mat4 transformation;

void main()
{
    gl_Position = mvpMatrix * vec4(position, 1.0);
    uvCoordinate = textureCoordinate;
    normals = (transformation * vec4(normal, 0)).xyz;
}