#include <stdio.h>


float racao_restante_apos_n_dias(float racao, unsigned int gatos, float racao_por_gato, unsigned int dias) {
    float consumo_diario_de_racao = racao_por_gato*gatos;
    float consumo_total_periodo = consumo_diario_de_racao*dias;
    return racao - consumo_total_periodo;
}

int main_funcao() {
    float saco_kg;
    puts("Digite o peso do saco de racao em kg");
    if (scanf("%f", &saco_kg) != 1) {
        fputs("Erro ao ler numero\n", stderr);
        return 1;
    }
    float gato_g;
    puts("Digite a quantidade de racao que cada gato consome em g");
    if (scanf("%f", &gato_g) != 1) {
        fputs("Erro ao ler numero\n", stderr);
        return 1;
    }
    float saco_g = saco_kg * 1000.0;
    float resto = racao_restante_apos_n_dias(saco_g, 2, gato_g, 5);
    //printf("A área de um triangulo de base %f e altura %f é %f\n", base, altura, area);
    return 0;
}

int main() {
    return main_funcao();
}