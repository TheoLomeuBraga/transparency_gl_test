#version 330 core
layout(location = 0) in vec3 vposition;

out vec4 fragColor;

uniform vec3 position;
uniform float scale;
uniform vec4 color;

void main() {

    
    gl_Position = vec4((vposition  * scale) + position, 1.0);
    fragColor = color;
}