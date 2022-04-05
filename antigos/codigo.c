#include <stdio.h>
#include <stdlib.h>
//ler um valor inteiro do teclado e dizer se pertence aos intervalos fechados [15:45] ou [66:99]
int main()
{
    int num;
    printf("Digite um numero inteiro: ");
    scanf("%d",&num);
   if(num>15, num<45){
    printf("o numero pertence ao intervalo fechado [15:45] ");
   }
   else{
   printf("o numero nao pertence ao intervalo");
   }
   if (num>66, num<99){
    printf("o numero pertence ao intervalo fechado [66:99] ");
   }
    else{
   printf("o numero nao pertence ao intervalo");
   }
}
