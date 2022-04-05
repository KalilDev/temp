#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int ler_int() {
    int entrada;
    if (scanf("%i", &entrada) != 1) {
        fputs("Erro ao ler int!\n", stderr);
        exit(EXIT_FAILURE);
        return 0xDEADBEEF;
    }
    return entrada;
}

bool numero_tem_4_digitos(int entrada) {
    if (entrada > 10000) {
        return false;
    }
    if (entrada < 1000) {
        return false;
    }
    return true;
}

int soma_das_partes_de_numero_de_4_digitos(int entrada) {
    assert(numero_tem_4_digitos(entrada));

    int parte_de_cima = entrada / 100;
    int parte_de_baixo = entrada % 100;

    return parte_de_cima+parte_de_baixo;
}

bool numero_corresponde_a_expectativa(int entrada) {
    assert(numero_tem_4_digitos(entrada));

    int soma_das_partes = soma_das_partes_de_numero_de_4_digitos(entrada);
    int quadrado_da_soma_das_partes = soma_das_partes*soma_das_partes;
    return entrada == quadrado_da_soma_das_partes;
}

int main() {
    int numero = ler_int();
    if (numero_corresponde_a_expectativa(numero)) {
        printf("O numero corresponde ao bagulho\n");
        return 0;
    }
    fprintf(stderr, "O numero não corresponde ao bagulho\n");
    return 1;
}
