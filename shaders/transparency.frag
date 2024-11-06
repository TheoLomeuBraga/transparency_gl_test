#version 330 core
in vec4 fragColor;
layout(location = 0) out vec4 accumColor;
layout(location = 1) out float accumWeight;

void main() {
    float alpha = fragColor.a;      // Opacidade do fragmento atual
    float weight = alpha;           // Peso baseado na opacidade

    // Acumula a cor ponderada pelo peso e a opacidade
    accumColor.rgb += fragColor.rgb * weight;
    accumColor.a += alpha;
    accumWeight += weight;
}