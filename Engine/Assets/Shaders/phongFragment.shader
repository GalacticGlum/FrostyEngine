#version 330

in vec2 uvCoordinate;
out vec4 fragColour;

uniform vec3 materialColour;
uniform vec3 ambientColour;

uniform sampler2D textureSampler;

void main()
{
    vec4 light = vec4(ambientColour, 1);
    vec4 colour = vec4(materialColour, 1);
    vec4 textureColour = texture2D(textureSampler, uvCoordinate.xy);

    if(textureColour != vec4(0, 0, 0, 1))
    {
        colour *= textureColour;
    }

    fragColour = colour * light;
}
