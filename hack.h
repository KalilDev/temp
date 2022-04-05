
#define CONVERSION_QUESTION(num, from, to) QUEST(num, {\
    printf("Digite um valor em %s:", #from);\
    float value = read_float_or_fail();\
    \
    printf("O valor em %s é %f\n", #to, from ## _from_ ## to(value));\
})
#define CONVERSION_PAIR_QUESTION(num_from, num_to, first_from, first_to) \
CONVERSION_QUESTION(num_from, first_from, first_to) \
CONVERSION_QUESTION(num_to, first_to, first_from) 

#define MASS_CONVERSION_QUESTION(num, from, to) QUEST(num, {\
    printf("Digite uma massa em %s:", #from);\
    float mass = read_float_or_fail();\
    \
    printf("A massa em %s é %f\n", #to, from ## _from_ ## to(mass));\
})
#define MASS_CONVERSION_PAIR_QUESTION(num_from, num_to, first_from, first_to) \
MASS_CONVERSION_QUESTION(num_from, first_from, first_to) \
MASS_CONVERSION_QUESTION(num_to, first_to, first_from) 

#define TEMPERATURE_CONVERSION_QUESTION(num, from, to) QUEST(num, {\
    printf("Digite uma temperatura em %s:", #from);\
    float temperature = read_float_or_fail();\
    \
    printf("A temperatura em %s é %f\n", #to, from ## _from_ ## to(temperature));\
})
#define TEMPERATURE_CONVERSION_PAIR_QUESTION(num_from, num_to, first_from, first_to) \
TEMPERATURE_CONVERSION_QUESTION(num_from, first_from, first_to) \
TEMPERATURE_CONVERSION_QUESTION(num_to, first_to, first_from) 

#define VELOCITY_CONVERSION_QUESTION(num, from, to) QUEST(num, {\
    printf("Digite uma velocidade em %s:", #from);\
    float velocity = read_float_or_fail();\
    \
    printf("A velocidade em %s é %f\n", #to, from ## _from_ ## to(velocity));\
})
#define VELOCITY_CONVERSION_PAIR_QUESTION(num_from, num_to, first_from, first_to) \
VELOCITY_CONVERSION_QUESTION(num_from, first_from, first_to) \
VELOCITY_CONVERSION_QUESTION(num_to, first_to, first_from) 

#define DISTANCE_CONVERSION_QUESTION(num, from, to) QUEST(num, {\
    printf("Digite uma distancia em %s:", #from);\
    float distance = read_float_or_fail();\
    \
    printf("A distancia em %s é %f\n", #to, from ## _from_ ## to(distance));\
})
#define DISTANCE_CONVERSION_PAIR_QUESTION(num_from, num_to, first_from, first_to) \
DISTANCE_CONVERSION_QUESTION(num_from, first_from, first_to) \
DISTANCE_CONVERSION_QUESTION(num_to, first_to, first_from) 

#define LENGTH_CONVERSION_QUESTION(num, from, to) QUEST(num, {\
    printf("Digite um comprimento em %s:", #from);\
    float length = read_float_or_fail();\
    \
    printf("O comprimento em %s é %f\n", #to, from ## _from_ ## to(length));\
})
#define LENGTH_CONVERSION_PAIR_QUESTION(num_from, num_to, first_from, first_to) \
LENGTH_CONVERSION_QUESTION(num_from, first_from, first_to) \
LENGTH_CONVERSION_QUESTION(num_to, first_to, first_from) 

#define AREA_CONVERSION_QUESTION(num, from, to) QUEST(num, {\
    printf("Digite uma area em %s:", #from);\
    float area = read_float_or_fail();\
    \
    printf("A area em %s é %f\n", #to, from ## _from_ ## to(area));\
})
#define AREA_CONVERSION_PAIR_QUESTION(num_from, num_to, first_from, first_to) \
AREA_CONVERSION_QUESTION(num_from, first_from, first_to) \
AREA_CONVERSION_QUESTION(num_to, first_to, first_from) 

#define VOLUME_CONVERSION_QUESTION(num, from, to) QUEST(num, {\
    printf("Digite um volume em %s:", #from);\
    float volume = read_float_or_fail();\
    \
    printf("O volume em %s é %f\n", #to, from ## _from_ ## to(volume));\
})
#define VOLUME_CONVERSION_PAIR_QUESTION(num_from, num_to, first_from, first_to) \
VOLUME_CONVERSION_QUESTION(num_from, first_from, first_to) \
VOLUME_CONVERSION_QUESTION(num_to, first_to, first_from) 

#define ANGLE_CONVERSION_QUESTION(num, from, to) QUEST(num, {\
    printf("Digite um ângulo em %s:", #from);\
    float theta = read_float_or_fail();\
    \
    printf("O ângulo em %s é %f\n", #to, from ## _from_ ## to(theta));\
})
#define ANGLE_CONVERSION_PAIR_QUESTION(num_from, num_to, first_from, first_to) \
ANGLE_CONVERSION_QUESTION(num_from, first_from, first_to) \
ANGLE_CONVERSION_QUESTION(num_to, first_to, first_from) 