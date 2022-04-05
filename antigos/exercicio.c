#include <stdio.h>

//fornecida para cada gato. Calcule e mostre quanto restará de ração no
//saco após 5 (cinco) dias
int main()
{
    int gatos= 2;
    int dias= 5;
    float racaogato1, racaogato2, sacokg, sacog, consumodia1, consumo5dias, restante5dias;
    dias=5;
    gatos = 2;

    printf("digite quantos quilos tem o saco de racao: ");
    scanf("%f", &sacokg);
    printf("digite a quantidade de ração (em gramas) fornecida ao gato 1 por dia: ");
    scanf("%f", &racaogato1);
    printf("digite a quantidade de ração (em gramas) fornecida ao gato 2 por dia: ");
    scanf("%f", &racaogato2);

    //peso do saco de kg pra g
    sacog= sacokg * 1000;
    consumodia1= racaogato1 + racaogato2;
    consumo5dias= consumodia1 * 5;
    restante5dias= sacog -consumo5dias;

    printf("o restante encontrado no saco de racao apos 5 dias eh %f", restante5dias);


    return 0;
}

