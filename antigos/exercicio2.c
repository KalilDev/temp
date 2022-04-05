#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float ler_float() {
    float entrada;
    if (scanf("%f", &entrada) != 1) {
        fputs("Erro ao ler float!\n", stderr);
        exit(EXIT_FAILURE);
        return NAN;
    }
    return entrada;
}

int ler_int() {
    int entrada;
    if (scanf("%i", &entrada) != 1) {
        fputs("Erro ao ler int!\n", stderr);
        exit(EXIT_FAILURE);
        return 0xDEADBEEF;
    }
    return entrada;
}

void trocar(int *a, int *b) {
    int b_temporario = *b;
    *b = *a;
    *a = b_temporario;
}

int duplicar(int numero) {
    return numero * 2;
}

int main() {
    int a = ler_int();
    int b = ler_int();

    trocar(&a, &b);

    printf("A e B %i %i\n", a, b);
    
    return 0;
}