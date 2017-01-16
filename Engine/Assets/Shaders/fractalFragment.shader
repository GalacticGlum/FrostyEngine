#version 430 core

out vec4 colour;

const int max_iterations = 255;

vec2 complex_square(vec2 v)
{
    return vec2(v.x*v.x - v.y*v.y,
    v.x*v.y*2.0);
}

void main(void)
{
    vec2 uv = gl_FragCoord.xy - vec2(400, 300); //half of window size
    uv *= 2.5 / min(800, 400);

    vec2 c = uv;
    vec2 v = vec2(0.0);
    float scale = 0.06;

    int count = max_iterations;
    for (int i = 0; i < max_iterations; i++)
    {
        v = c + complex_square(v);
        if (dot(v, v) > 4.0)
        {
            count = i;
            break;
        }
    }

    colour = vec4(float(count) * scale);
}