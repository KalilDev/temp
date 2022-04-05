entrada peso_do_saco_kg
entrada quantidade_racao_gato_1_g
entrada quantidade_racao_gato_2_g

numero kg_para_grama(kg) {
    retorna 1000*kg;
}

saco_em_g = kg_para_grama(peso_do_saco_kg)

consumido_em_um_dia_g = quantidade_racao_gato_1_g
                     +  quantidade_racao_gato_2_g

consumido_em_5_dias_g = consumido_em_um_dia_g*5

total_g = saco_em_g

restante_apos_5_dias = total_g-consumido_em_5_dias_g

saida restante_apos_5_dias