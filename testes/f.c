#include <stdio.h>

float percent_to_factor(float percent) {
    return percent/100.0;
}

float salario_com_aumento(float salario, float factor) {
    return salario*factor;
}

int main_funcao() {
    float salario;
    puts("Digite o salário");
    if (scanf("%f", &salario) != 1) {
        fputs("Erro ao ler numero\n", stderr);
        return 1;
    }
    float aumento_percent;
    puts("Digite a porcentagem do aumento");
    if (scanf("%f", &aumento_percent) != 1) {
        fputs("Erro ao ler numero\n", stderr);
        return 1;
    }
    float porcentagem_resultante = 100.0+aumento_percent;
    float salario_final = salario_com_aumento(salario, percent_to_factor(porcentagem_resultante));
    printf("R$%f com %f", salario, aumento_percent);
    fputs("%", stdout);
    printf(" de aumento são R$%f\n", salario_final);
    return 0;
}

int main() {
    return main_funcao();
}