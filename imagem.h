#ifndef IMAGEM_H
#define IMAGEM_H

typedef struct {
    int codigo_alerta;
    float area;
    char data_foto_antes[11];
    char data_foto_depois[11];
    char estado[3];
    char municipio[50];
} Imagem;

#endif
