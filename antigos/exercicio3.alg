/* Em C */
float soma_de_termos_da_pa(float n, float a1, float an) {
    return n*(a1+an)/2;
}

float ler_float() {
    float entrada;
    if (scanf("%f", &entrada) != 1) {
        puts("erro!");
        return 0.0;
    }
    return entrada;
}

int ler_int() {
    int entrada;
    if (scanf("%i", &entrada) != 1) {
        puts("erro!");
        return 0;
    }
    return entrada;
}

/* Pseudocodigo
numero soma_de_termos_da_pa(n, a1, an) {
    retornar n*(a1+an)/2;
}


numero enesimo_termo_pa(a1, n, r) {
    retornar a1+(n-1)*r;
}

numero r_a_partir_de_consecutivos(primeiro, segundo) {
    retornar segundo - primeiro
}

entrada primero_termo
entrada segundo_termo
entrada n

r = r_a_partir_de_consecutivos(primero_termo, segundo_termo)

enesimo = enesimo_termo_pa(primero_termo, n, r)

soma_de_termos = soma_de_termos_da_pa(n, primero_termo, enesimo)

saida soma_dos_termos

*/