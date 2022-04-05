#include <stdio.h>

float area_de_triangulo(float base, float altura) {
    return (base*altura)/2.0;
}

int main_funcao() {
    float base;
    puts("Digite a base");
    if (scanf("%f", &base) != 1) {
        fputs("Erro ao ler numero\n", stderr);
        return 1;
    }
    float altura;
    puts("Digite a altura");
    if (scanf("%f", &altura) != 1) {
        fputs("Erro ao ler numero\n", stderr);
        return 1;
    }
    float area = area_de_triangulo(base, altura);
    printf("A área de um triangulo de base %f e altura %f é %f\n", base, altura, area);
    return 0;
}

int main() {
    return main_funcao();
}