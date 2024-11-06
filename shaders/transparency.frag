#version 430 core
uniform vec4 color;

layout(location = 0) out vec4 accumColor;
layout(location = 1) out float accumWeight;

void main() {
    float alpha = color.a;
    float weight = alpha;

    accumColor.rgb = color.rgb * weight;
    accumColor.a = alpha;
    accumWeight = weight;
}
