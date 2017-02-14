#version 330 

layout (location = 0) in vec3 position;

out vec4 pos;
uniform mat4 mvpMatrix;
uniform mat4 transformationMatrix;

void main()
{
    gl_Position = mvpMatrix * vec4(position, 1.0);
    pos = transformationMatrix * vec4(position, 1.0);
}