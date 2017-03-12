#version 450

const int MAX_POINT_LIGHTS = 10;
const int MAX_SPOT_LIGHTS = 10;

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

struct AttenuationCurve
{
    float constantFactor;
    float linearFactor;
    float exponentialFactor;
};

struct PointLight
{
    BaseLight baseLight;
    AttenuationCurve attenuation;
    vec3 position;
    float radius;
};

struct SpotLight
{
    PointLight pointLight;
    vec3 direction;
    float cutoff;
};

in vec2 uvCoordinate;
in vec3 normals;
in vec3 worldPosition;
out vec4 fragColour;

uniform vec3 materialColour;
uniform vec3 ambientColour;
uniform sampler2D textureSampler;

uniform DirectionalLight directionalLight;

// TODO: Use uniform buffer.
uniform PointLight pointLights[MAX_POINT_LIGHTS];
uniform SpotLight spotLights[MAX_SPOT_LIGHTS];

uniform vec3 cameraPosition;
uniform float specularIntensity;
uniform float specularPower;

vec4 calculateLight(BaseLight baseLight, vec3 direction, vec3 normal)
{
    float diffuseFactor = dot(normal, -direction);

    vec4 diffuseColour; 
    vec4 specular;

    if(diffuseFactor > 0)
    {
        diffuseColour = vec4(baseLight.colour, 1.0) * baseLight.intensity * diffuseFactor;
        
        vec3 cameraDirection = normalize(cameraPosition - worldPosition);
        vec3 reflectionDirection =  normalize(reflect(direction, normal));

        float specularFactor = dot(cameraDirection, reflectionDirection);
        specularFactor = pow(specularFactor, specularPower);

        if(specularFactor > 0)
        {
            specular = vec4(baseLight.colour,  1.0) * specularIntensity * specularFactor;
        }
    }

    return diffuseColour + specular;
}

vec4 calculateDirectionalLight(DirectionalLight directionalLight, vec3 normal)
{
    return calculateLight(directionalLight.baseLight, -directionalLight.direction, normal);
}

vec4 calculatePointLight(PointLight pointLight, vec3 normal)
{
    vec3 direction = worldPosition - pointLight.position;
    float directionDistance = length(direction);

    if(directionDistance > pointLight.radius)
    {
        return vec4(0, 0, 0, 0);
    }

    direction = normalize(direction);

    vec4 lightColour = calculateLight(pointLight.baseLight, direction, normal);
    float attenuation = pointLight.attenuation.constantFactor +
        pointLight.attenuation.linearFactor * directionDistance +
        pointLight.attenuation.exponentialFactor * pow(directionDistance, 2);

    return lightColour / attenuation;
}

vec4 calculateSpotLight(SpotLight spotLight, vec3 normal)
{
    vec3 direction = normalize(worldPosition - spotLight.pointLight.position);
    float factor = dot(direction, normalize(spotLight.direction));
    
    vec4 result = vec4(0, 0, 0, 0);
    if(factor > spotLight.cutoff)
    {
        result = calculatePointLight(spotLight.pointLight, normal) * (1.0 - (1.0 - factor) / (1.0 - spotLight.cutoff));
    }

    return result;
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

    vec3 surfaceNormal = normalize(normals);

    light += calculateDirectionalLight(directionalLight, surfaceNormal);
    for(int i = 0; i < MAX_POINT_LIGHTS; i++)
    {
        if(pointLights[i].baseLight.intensity > 0)
        {
            light += calculatePointLight(pointLights[i], surfaceNormal);
        }
    }

    for(int i = 0; i < MAX_SPOT_LIGHTS; i++)
    {
        if(spotLights[i].pointLight.baseLight.intensity > 0)
        {
            light += calculateSpotLight(spotLights[i], surfaceNormal);
        }
    }

    fragColour = colour * light;
}
