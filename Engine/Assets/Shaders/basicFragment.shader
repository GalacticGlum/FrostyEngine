#version 330

in vec2 uvCoordinate;
out vec4 fragColour;

uniform vec3 colour;
uniform sampler2D textureSampler;

void main()
{
    vec4 textureColour = texture2D(textureSampler, uvCoordinate.xy);
    if(textureColour == vec4(0, 0, 0, 1))
    {
        fragColour =  vec4(colour, 1);
    }
    else
    {
        fragColour =  textureColour * vec4(colour, 1);
    }
}
