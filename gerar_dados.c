#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gerar_dados.h"

void gerar_dados_internos(Imagem imagens[], int n) {
    const char* estados[] = {"AC", "AP", "AM", "MA", "MT", "PA", "RO", "RR", "TO"};
    const char* municipios[] = {
        "Rio Branco", "Macapa", "Manaus", "Sao Luis", "Cuiaba", "Belem", "Porto Velho", "Boa Vista", "Palmas",
        "Cruzeiro do Sul", "Santarem", "Maraba", "Ji-Parana", "Altamira", "Itaituba", "Paragominas", "Barcarena",
        "Sinop", "Vilhena", "Humaita"
    };
    int num_estados = 9;
    int num_municipios = 9;

    for (int i = 0; i < n; i++) {
        imagens[i].codigo_alerta = rand() % 1000000;  // Gera valores aleatórios entre 0 e 999999
        imagens[i].area = ((float)rand() / (float)(RAND_MAX)) * 100.0;  // Área aleatória entre 0 e 100
        snprintf(imagens[i].data_inicio, 11, "%02d/%02d/%04d", rand() % 30 + 1, rand() % 12 + 1, 2000 + rand() % 23);  // Datas aleatórias entre 2000 e 2022
        snprintf(imagens[i].data_fim, 11, "%02d/%02d/%04d", rand() % 30 + 1, rand() % 12 + 1, 2000 + rand() % 23);
        snprintf(imagens[i].estado, 3, "%s", estados[rand() % num_estados]);
        snprintf(imagens[i].municipio, 50, "%s", municipios[rand() % num_municipios]);
    }
}