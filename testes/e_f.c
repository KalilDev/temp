#include <stdio.h>

float fahrenheit_from_celsius(float celsius) {
    return (9.0/5.0)*celsius+32.0;
}

float celsius_from_fahrenheit(float fahrenheit) {
    return (5.0/9.0)*(fahrenheit-32.0);
}

typedef enum unit_type {
    unknown,
    celcius,
    fahrenheit,
} unit_type_t;

int main_funcao() {
    float input;
    puts("Digite a temperatura para ser convertida");
    if (scanf("%f", &input) != 1) {
        fputs("Erro ao ler numero\n", stderr);
        return 1;
    }
    printf("%f°", input);

    unit_type_t type = unknown;
    while (type == unknown) {
        char kind  = getchar();
        switch (kind) {
            case 'c':
            case 'C':
                type = celcius;
                break;
            case 'f':
            case 'F':
                type = fahrenheit;
                break;
        }
    }

    char input_measure_unit;
    float converted;
    char converted_measure_unit;
    switch (type) {
        case celcius:
            input_measure_unit = 'C';
            converted = fahrenheit_from_celsius(input);
            converted_measure_unit = 'F';
            break;
        case fahrenheit:
            input_measure_unit = 'F';
            converted = celsius_from_fahrenheit(input);
            converted_measure_unit = 'C';
            break;
        case unknown:
            return 1;
    }

    printf("%f°%c são %f°%c\n", input, input_measure_unit, converted, converted_measure_unit);
    return 0;
}

int main() {
    return main_funcao();
}