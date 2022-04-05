#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

int ler_int() {
    int entrada;
    if (scanf("%i", &entrada) != 1) {
        fputs("Erro ao ler int!\n", stderr);
        exit(EXIT_FAILURE);
        return 0xDEADBEEF;
    }
    return entrada;
}


/*void trocar(ponteiro a, ponteiro b) {
    temporario_a = ler a
    escrever a = ler b
    escrever b = temporario_a
}*/
void trocar(int *a, int *b) {
    int temporario_a = *a;
    *a = *b;
    *b = temporario_a;
}

// XOR: OR exclusivo
void print_bools(bool a,bool b) {
    bool resultado = a^b;
    printf("%i e %i = %i\n",a, b, resultado);
}

int main() {
    print_bools(true, true);
    print_bools(true, false);
    print_bools(false, true);
    print_bools(false, false);
    print_bools(10, 2);
    return 0;
}