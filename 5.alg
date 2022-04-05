Construa um algoritmo que receba como entrada tres valores (A,B,C).
Apos o processamento o menor valor deverá estar em A e o maior valor
em C, e o valor intermediario em B.
Imprima A,B,C


entrada A
entrada B
entrada C

void trocar(ponteiro a, ponteiro b) {
    temporario_a = ler a
    escrever a = ler b
    escrever b = temporario_a
}

void assert(bool condicao) {
    if (condicao) {
        return;
    }
    printf("Erro fatal!!! Corrija seu programa");
    exit(ERRO);
}

if (A > B) {
    trocar(A, B)
}
assert(B > A);

if (B > C) {
    trocar(B, C)
}
assert(C > B);

if (A > B) {
    trocar(A, B)
}

assert(C > B);
assert(C > A);
assert(B > A);



saida A
saida B
saida C