#version 430 core
layout(location = 0) in vec3 vposition;

uniform vec3 position;
uniform float scale;


void main() {

    
    gl_Position = vec4((vposition  * scale) + position, 1.0);
}