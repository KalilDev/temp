#include <stdio.h>

// TODO!!
int main()
{
    int quantidade = 0, total = 0;
    for (;;) {
        int valor;
        // Ler o valor e checar se houve erro.
        if (scanf(" %d", &valor) == 0) {
            // Caso ja tenha 2 ou mais valores mostre a media
            if (quantidade >= 2) {
                break;
            }
            // Caso nao, saia com o erro
            fprintf(stderr, "Impossivel ler numero!\n");
            return 1;
        }
        printf("scaneado %i\n", valor);
        quantidade++;
        total+=valor;
    }
    /* Não é necessario pq sempre a quantidade vai ser maior que 2.
    if (quantidade < 2) {
        fprintf(stderr, "Foram passados somente %i valores, quando devia ser 2+.", quantidade);
        return 1;
    }*/
    float media = total/quantidade;
    printf("A média dos %i valores é %f\n", quantidade, media);
    return 0;
}