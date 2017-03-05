#version 450

struct BaseLight
{
    vec3 colour;
    float intensity;
};

struct DirectionalLight
{
    BaseLight baseLight;
    vec3 direction;
};

in vec2 uvCoordinate;
in vec3 normals;
out vec4 fragColour;

uniform vec3 materialColour;
uniform vec3 ambientColour;
uniform sampler2D textureSampler;
uniform DirectionalLight directionalLight;

vec4 calculateLight(BaseLight baseLight, vec3 direction, vec3 normal)
{
    float diffuseFactor = dot(normal, -direction);
    vec4 diffuseColour = vec4(0, 0, 0, 0); 

    if(diffuseFactor > 0)
    {
        diffuseColour = vec4(baseLight.colour, 1.0) * baseLight.intensity * diffuseFactor;
    }

    return diffuseColour;
}

vec4 calculateDirectionalLight(DirectionalLight directionalLight, vec3 normal)
{
    return calculateLight(directionalLight.baseLight, -directionalLight.direction, normal);
}

void main()
{
    vec4 light = vec4(ambientColour, 1);
    vec4 colour = vec4(materialColour, 1);
    vec4 textureColour = texture2D(textureSampler, uvCoordinate.xy);

    if(textureColour != vec4(0, 0, 0, 1))
    {
        colour *= textureColour;
    }

    light += calculateDirectionalLight(directionalLight, normalize(normals));
    fragColour = colour * light;
}
