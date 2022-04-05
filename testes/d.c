#include <stdio.h>
#include <stdbool.h>

typedef struct nota_e_peso {
    float nota;
    float peso;
} nota_e_peso_t;

typedef struct talvez_nota_e_peso {
    bool erro;
    nota_e_peso_t nota;
} talvez_nota_e_peso_t;

talvez_nota_e_peso_t scan_nota_e_peso() {
    struct nota_e_peso valor;
    bool erro = false;
    if (scanf("%f:%f", &valor.nota, &valor.peso) < 2) {
        valor.nota=0.0;
        valor.peso=0.0;
        erro=true;
    }
    talvez_nota_e_peso_t resultado = {.erro=erro, .nota=valor};
    return resultado;
}

float weighted_avg_total(float total, float total_weight)
{
    return total/total_weight;
}


float weighted_avg_values_and_weigth_pairs(float* values_and_weigths, size_t count)
{
    float total = 0.0;
    float total_weight = 0.0;
    for (size_t i =0; i <count*2; i+=2) {
        total+=values_and_weigths[i];
        total_weight+=values_and_weigths[i+1];
    }
    return weighted_avg_total(total, total_weight);
}

float weighted_avg_values_and_weigths(float* values, float* weigths, size_t count)
{
    float total = 0.0;
    float total_weight = 0.0;
    for (size_t i =0; i <count; i++) {
        total+=values[i];
    }
    for (size_t i =0; i <count; i++) {
        total_weight+=values[i];
    }
    return weighted_avg_total(total, total_weight);

}

int main_struct() {
    struct nota_e_peso total = {0.0,0.0};
    for (int i=0;i<3;i++) {
        puts("Digite a nota e o peso no formato nota:peso");
        talvez_nota_e_peso_t resultado = scan_nota_e_peso();
        if (resultado.erro) {
            i--;
            puts("Tente novamente");
            continue;
        }
        total.nota+=resultado.nota.nota;
        total.peso+=resultado.nota.peso;
    }
    float media_ponderada = weighted_avg_total(total.nota, total.peso);
    float* total_hack = (float*)(&total);
    printf("O total é %f, %f\n", total.nota, total.peso);
    printf("O total é %f, %f\n", total_hack[0], total_hack[1]);
    printf("A media ponderada é %f\n", media_ponderada);
    return 0;
}

int main_julinha() {
    float total = 0.0;
    float peso_total = 0.0;
    for (int i=0;i<3;i++) {
        float nota, peso;
        puts("Digite a nota e o peso no formato nota:peso");
        if (scanf("%f:%f", &nota, &peso) < 2) {
            i--;
            puts("Tente novamente");
            continue;
        }
        total+=nota;
        peso_total+=peso;
    }
    float media_ponderada = total/peso_total;
    printf("O total é %f, %f\n", total, peso_total);
    printf("A media ponderada é %f\n", media_ponderada);
    return 0;
}

// TODO!!
int main()
{
    return main_julinha();
}