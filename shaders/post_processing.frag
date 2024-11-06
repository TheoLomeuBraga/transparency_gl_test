#version 430 core
uniform sampler2D colorTexture;
uniform sampler2D weightTexture;

out vec4 finalColor;

void main() {
    vec2 uv = gl_FragCoord.xy / vec2(textureSize(colorTexture, 0));

    vec3 colorAccum = texture(colorTexture, uv).rgb;
    float weightAccum = texture(weightTexture, uv).r;
    
    finalColor.rgb = colorAccum / max(weightAccum, 0.0001);
    finalColor.a = weightAccum;
    
    finalColor = texture(colorTexture, uv);
}
