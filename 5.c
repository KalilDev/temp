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

int main() {
    int A = ler_int();
    int B = ler_int();
    int C = ler_int();

    printf("%i, %i, %i\n", A, B, C);

    if (A > B) {
        trocar(&A, &B);
    }
    assert(B > A);

    if (B > C) {
        trocar(&B, &C);
    }
    assert(C > B);

    if (A > B) {
        trocar(&A, &B);
    }

    assert(C > B);
    assert(C > A);
    assert(B > A);

    assert(false);


    printf("%i, %i, %i\n", A, B, C);
    return 0;
}