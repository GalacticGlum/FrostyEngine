#version 330

in vec4 pos;
out vec4 fragColour;

uniform vec4 colour;
uniform vec2 lightPosition;

void main()
{
    fragColour = colour * (1.0 / length(distance(pos.xy, lightPosition)));
}
