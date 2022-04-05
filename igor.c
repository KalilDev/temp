#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "hack.h"
#define FLOAT_CONVERSION_BLOCK(a, b, a_from_b_block, b_from_a_block)\
float a ## _from_ ## b(float b) a_from_b_block \
\
float b ## _from_ ## a(float a) b_from_a_block 

#define FLOAT_CONVERSION(a, b, a_from_b, b_from_a) FLOAT_CONVERSION_BLOCK(a, b, { return a_from_b; }, { return b_from_a; })

#define QUEST(num, bloco) \
        case num:\
            printf("Questão número %i:\n", num);\
            bloco\
            if (question != -1) {\
                break;\
            }

//#define RUN_QUEST(num) questao_ ## num();
#define SQUARE(num) (num*num)

#define START_QUESTS \
void _$run_question(int question) {\
    switch (question){\
        case -1:
#define END_QUESTS \
        default:\
            if (question != -1) {\
                printf("Invalid question number %i!\n", question);\
                exit(1);\
            }\
    }\
}

#define RUN_ALL_QUESTS() _$run_question(-1);
#define RUN_QUEST(num) _$run_question((unsigned int)num);

typedef enum {
    decimal_or_octal,
    decimal,
    octal,
} read_int_format;

typedef struct {
    float value;
    bool error;
} read_float_result_t;

typedef struct {
    int value;
    bool error;
} read_int_result_t;

read_float_result_t read_float() {
    read_float_result_t result = {.value = NAN};
    result.error = scanf("%f", &result.value) != 1;
    return result;
}

read_int_result_t read_int(read_int_format format) {
    read_int_result_t result = {.value = 0xDEADBEEF};
    const char* format_string;
    switch (format) {
        case decimal_or_octal: format_string="%i";break;
        case decimal: format_string="%d";break;
        case octal: format_string="%o";break;
        default:
            result.error = true;
            return result;
    }
    result.error = scanf("%i", &result.value) != 1;
    return result;
}

float read_float_or_fail() {
    read_float_result_t result = read_float();
    if (result.error) {
        fputs("Não foi possivel ler o float!\n", stderr);
        exit(EXIT_FAILURE);
        // unreachable
        assert(false);
    }
    return result.value;
}

int read_int_or_fail(read_int_format format) {
    read_int_result_t result = read_int(format);
    if (result.error) {
        fputs("Não foi possivel ler o int!\n", stderr);
        exit(EXIT_FAILURE);
        // unreachable
        assert(false);
    }
    return result.value;
}

int sum_of_ints(int *ints, size_t count) {
    int acc = 0;
    for (size_t i=0;i < count; i++) {
        acc+=ints[i];
    }
    return acc;
}

float sum_of_floats(float *vals, size_t count) {
    float acc = 0.0;
    for (size_t i=0;i < count; i++) {
        acc+=vals[i];
    }
    return acc;
}

float avg_of_floats(float *vals, size_t count) {
    float sum = sum_of_floats(vals, count);
    return sum/(float)count;
}

float avg_of_ints(int *ints, size_t count) {
    int sum = sum_of_ints(ints, count);
    return sum/(float)count;
}

float sum_of_squares_of_ints(int *vals, size_t count) {
    int sum_of_squares = 0;
    for (size_t i = 0; i < count; i++) {
        int value = vals[i];
        sum_of_squares += SQUARE(value);
    }
    return sum_of_squares;
}


float sum_of_squares_of_floats(float *vals, size_t count) {
    float sum_of_squares = 0.0;
    for (size_t i = 0; i < count; i++) {
        float value = vals[i];
        sum_of_squares += SQUARE(value);
    }
    return sum_of_squares;
}

int promt_int_or_fail(read_int_format format) {
    puts("Digite um numero inteiro:");
    return read_int_or_fail(format);
}

void promt_ints_or_fail(int *out, size_t count, read_int_format format) {
    const char *suffix;
    if (count>1) {
        suffix = "s";
    } else {
        suffix = "";
    }
    printf("Digite %li numero%s inteiro%s:\n", count, suffix, suffix);
    for (size_t i=0; i < count; i++) {
        out[i] = read_int_or_fail(format);
    }
}

void promt_floats_or_fail(float *out, size_t count) {
    const char *suffix;
    const char *real;
    if (count>1) {
        suffix = "s";
        real = "reais";
    } else {
        suffix = "";
        real = "real";
    }
    printf("Digite %li numero%s %s:\n", count, suffix, real);
    for (size_t i=0; i < count; i++) {
        out[i] = read_float_or_fail();
    }
}

int promt_dint_or_fail() {
    return promt_int_or_fail(decimal);
}
float promt_float_or_fail() {
    puts("Digite um numero real:");
    return read_float_or_fail();
}



FLOAT_CONVERSION(celsius, fahrenheit, 5.0*((fahrenheit - 32.0)/9.0), (celsius/5.0)*9.0 + 32.0)
FLOAT_CONVERSION(kelvin, celsius, celsius+273.15, kelvin-273.15)
FLOAT_CONVERSION(km_h, m_s, m_s*3.6, km_h/3.6)
FLOAT_CONVERSION(mile, km, km/1.61, mile*1.61)
FLOAT_CONVERSION(rad, deg, (deg*M_PI)/180.0, (rad/M_PI)*180.0)
FLOAT_CONVERSION(pol, cm, cm/2.54, pol*2.54)
FLOAT_CONVERSION(lt, m_3, m_3*1000.0, lt/1000.0)
FLOAT_CONVERSION(kg, lb, lb*0.45, kg/0.45);
FLOAT_CONVERSION(yd, m, m/0.91, yd*0.91);
FLOAT_CONVERSION(m_2, ac, ac*4048.58, m_2*0.000247);
FLOAT_CONVERSION(m_2, hec, hec/10000.0, m_2*10000.0)


float area_de_circulo(float raio) {
    return M_PI*SQUARE(raio);
}

float hipotenusa_de_catetos(float a, float b) {
    float a2 = SQUARE(a);
    float b2 = SQUARE(b);
    return sqrtf(a2+b2);
}

START_QUESTS
QUEST(1, {
    int number = promt_dint_or_fail();
    printf("%d\n", number);
})


QUEST(2, {
    float number = promt_float_or_fail();
    printf("%f\n", number);
})

QUEST(3, {
    int nums[3];
    promt_ints_or_fail(nums, 3, decimal);
    int sum = sum_of_ints(nums, 3);
    printf("A soma deles é %i\n", sum);
})

QUEST(4, {
    float numero = promt_float_or_fail();

    printf("O quadrado dele é %f\n", SQUARE(numero));
})

QUEST(5, {
    float numero = promt_float_or_fail();

    printf("O quinto dele é %f\n", numero/5.0);
})

TEMPERATURE_CONVERSION_PAIR_QUESTION(6, 7, fahrenheit, celsius);



TEMPERATURE_CONVERSION_PAIR_QUESTION(8, 9, kelvin, celsius);

VELOCITY_CONVERSION_PAIR_QUESTION(10, 11, m_s, km_h);



DISTANCE_CONVERSION_PAIR_QUESTION(12, 13, mile, km);

ANGLE_CONVERSION_PAIR_QUESTION(14, 15, rad, deg);


LENGTH_CONVERSION_PAIR_QUESTION(16, 17, cm, pol);


VOLUME_CONVERSION_PAIR_QUESTION(18, 19, lt, m_3);



MASS_CONVERSION_PAIR_QUESTION(20, 21, kg, lb);


LENGTH_CONVERSION_PAIR_QUESTION(22, 23, m, yd);


AREA_CONVERSION_PAIR_QUESTION(24, 25, m_2, ac);

AREA_CONVERSION_PAIR_QUESTION(26, 27, m_2, hec);

QUEST(28, {
    float nums[3];
    promt_floats_or_fail(nums, 3);
    float sum_of_squares = sum_of_squares_of_floats(nums, 3);
    printf("A soma do quadrado deles é %f\n", sum_of_squares);
})

QUEST(29, {
    float nums[4];
    promt_floats_or_fail(nums, 4);
    float avg = avg_of_floats(nums, 4);
    printf("A média das notas é %f\n", avg);
})

QUEST(30, {
    puts("Digite um valor em reais e a cotacao do dólar");
    float reais = read_float_or_fail();
    float cotacao_dolar = read_float_or_fail();

    float em_dolares=reais/cotacao_dolar;

    printf("O valor em dólares é %f\n", em_dolares);
})

QUEST(31, {
    int num = promt_dint_or_fail();
    int antecessor = num-1;
    int sucessor = num+1;

    printf("O antecessor é %i e o sucessor é %i\n", antecessor, sucessor);
})

QUEST(32, {
    int num = promt_dint_or_fail();
    int antecessor_do_dobro = (num*2)-1;
    int sucessor_do_triplo = (num*3)+1;

    int result = sucessor_do_triplo + antecessor_do_dobro;

    printf("O resultado é %i\n", result);
})


QUEST(33, {
    float lado = promt_float_or_fail();

    printf("A área do quadrado é %f\n", SQUARE(lado));
})

QUEST(34, {
    float raio = promt_float_or_fail();

    printf("A área do círculo é %f\n", area_de_circulo(raio));
})

QUEST(35, {
    float catetos[2];
    promt_floats_or_fail(catetos, 2);


    printf("A hipotenusa é %f\n", hipotenusa_de_catetos(catetos[0], catetos[1]));
})

QUEST(36, {
    puts("Digite a altura e o raio");
    float altura = read_float_or_fail();
    float raio = read_float_or_fail();
    
    float area_base =  area_de_circulo(raio);
    float volume = area_base*altura;

    printf("A volume é %f\n", volume);
})

QUEST(37, {
    float valor = promt_float_or_fail();
    const float desconto = 0.12;
    float valor_final = valor - (valor*desconto);
    
    printf("A valor com desconto é %f\n", valor_final);
})

QUEST(38, {
    float salario = promt_float_or_fail();
    const float aumento = 0.25;

    float salario_final = salario + (salario*aumento);
    
    printf("O salário com o aumento é %f\n", salario_final);
})

QUEST(39, {
    const float quantia = 780000.0;
    const float fator_primeiro = 0.46;
    const float fator_segundo = 0.32;
    const float fator_terceiro = 1.0-fator_primeiro-fator_segundo;

    float primeiro = quantia*fator_primeiro;
    float segundo = quantia*fator_segundo;
    float terceiro = quantia*fator_terceiro;
    
    printf("O valor recebido pelo primeiro, segundo e terceiro foi, respectivamente, %f; %f; %f\n", primeiro, segundo, terceiro);
})


QUEST(40, {
    const float diaria = 30.0;
    const float fator_com_imposto = 1.08;
    int dias = promt_dint_or_fail();

    float diarias = diaria * dias;
    float diarias_com_imposto = diarias/fator_com_imposto;
    
    printf("O valor a ser pago com o imposto é %f\n", diarias_com_imposto);
})

QUEST(41, {
    float valor_hora = promt_float_or_fail();
    int horas = promt_dint_or_fail();
    
    const float fator = 1.1;

    float final = horas*valor_hora*fator;

    printf("O valor a ser pago é %f\n", final);
})

QUEST(42, {
    float salario_base = promt_float_or_fail();
    
    const float fator_gratificado = 1.05;
    const float fator_depois_imposto = 0.93;

    float final = salario_base*fator_gratificado*fator_depois_imposto;

    printf("O valor do salário é %f\n", final);
})

QUEST(43, {
    float valor_base = promt_float_or_fail();
    
    const float fator_com_10_desconto = 0.9;
    const float um_terco = 1.0/3.0;
    const float fator_comissao = 0.05;

    float valor_desconto = valor_base*fator_com_10_desconto;
    float valor_parcela = valor_base*um_terco;
    float comissao_vendedor_vista = valor_desconto*fator_comissao;
    float comissao_vendedor_parcelado = valor_base*fator_comissao;

    printf("O valor com desconto é %f, o de cada parcela é %f, o da comissao à vista é %f e o da comissao parcelada é %f\n", valor_desconto, valor_parcela, comissao_vendedor_vista, comissao_vendedor_parcelado);
})
QUEST(44, {
    puts("Digite a altura do degrau e da escada");
    float altura_degrau = read_float_or_fail();
    float altura_escada = read_float_or_fail();
    
    float total_degraus = altura_escada/altura_degrau;
    int degraus = ceilf(total_degraus);
    printf("Deverá subir %i degraus\n", degraus);
})

QUEST(45, {
    int character = promt_dint_or_fail();
    if (character > 0xff) {
        printf("Caractere n é ascii!\n");
    } else {
        // CONVERT

    }
})


END_QUESTS




int main() {
    RUN_QUEST(22);
    RUN_QUEST(23);
    RUN_ALL_QUESTS();
    return 0;
}