#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Bernardo, Eustaquio, Luiz, Mario, Arthur, numero;

    printf("escreva um numero de tres digitos com os numeros 1, 2 e 3: ");
    scanf("%d", &numero);

    if (numero == 221){
        printf("Bernardo");
    } else if (numero == 211){
        printf("Eustaquio");
    } else if (numero == 311){
        printf("Luiz");
    } else if (numero == 312){
        printf("Mario");
    } else if (numero == 332){
        printf("Arthur");
    } else {
        printf("\nerro");
    }
}