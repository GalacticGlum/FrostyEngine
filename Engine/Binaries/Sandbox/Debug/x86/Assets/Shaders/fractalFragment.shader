#version 430 core

out vec4 colour;
uniform float zoom;

const int max_iterations = 255;

vec2 complex_square(vec2 v)
{
    return vec2(v.x*v.x - v.y*v.y,v.x*v.y * 2);
}

void main()
{
    vec2 uv = gl_FragCoord.xy - vec2(50, 450); //half of window size
    uv *= 2.5 / min(800*zoom, 600*zoom);

    vec2 c = uv;
    vec2 v = vec2(0.0);
    float scale = 0.06;

    int count = max_iterations;
    for (int i = 0; i < max_iterations; i++)
    {
        v = c + complex_square(v);
        if (dot(v, v) > 4)
        {
            count = i;
            break;
        }
    }

    colour = vec4(197.0/255.0, 66.0/255.0, 244.0/255.0, 1) *  float(count) * scale;
}