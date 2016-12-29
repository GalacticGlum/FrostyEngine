#version 330

out vec4 colour;
in vec4 outColour;

void main()
{
    colour = outColour;
}