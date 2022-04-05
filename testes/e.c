#include <stdio.h>

float fahrenheit_from_celsius(float celsius) {
    return (9.0/5.0)*celsius+32.0;
}

int main_funcao() {
    float celsius;
    puts("Digite a temperatura em ℃ para ser convertida em ℉");
    if (scanf("%f", &celsius) != 1) {
        fputs("Erro ao ler numero\n", stderr);
        return 1;
    }
    float fahrenheit = fahrenheit_from_celsius(celsius);
    printf("%f℃ são %f℉\n", celsius, fahrenheit);
    return 0;
}

int main_julinha() {
    float celsius;
    puts("Digite a temperatura em ℃ para ser convertida em ℉");
    if (scanf("%f", &celsius) != 1) {
        fputs("Erro ao ler numero\n", stderr);
        return 1;
    }
    float fahrenheit = (9.0/5.0)*celsius+32.0;
    printf("%f℃ são %f℉\n", celsius, fahrenheit);
    return 0;
}

int main() {
    return main_julinha();
}