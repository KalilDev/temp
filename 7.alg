O numero 3025 possui a seguinte caracteristicas
30 + 25 = 55
55^2 = 3025

Fazer um algoritmo que dado um numero de 4 digitos
(verifique) calcule e escreva se ele posssui ou
nao essta caracteristica.

entrada numero


if (!numero_tem_4_digitos(numero)) {
    return 1
}

bool numero_tem_4_digitos(numero entrada) {
    if (numero > 10000) {
        return false
    }
    if (numero < 1000) {
        return false
    }
    return true
}

numero soma_das_partes_de_numero_de_4_digitos(numero entrada) {
    assert(numero_tem_4_digitos(numero))
    parte_de_cima = entrada / 100
    parte_de_cima = 30
    parte_de_baixo = entrada~/100
    parte_de_baixo = 25

    return parte_de_cima+parte_de_baixo
}

bool numero_corresponde_a_expectativa(numero entrada) {
    assert(numero_tem_4_digitos(numero))

    soma_das_partes = soma_das_partes(numero)

    quadrado_da_soma_das_partes = soma_das_partes*soma_das_partes
    
    return entrada == quadrado_da_soma_das_partes;
}





