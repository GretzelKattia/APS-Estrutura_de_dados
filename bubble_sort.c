#include "bubble_sort.h"

void bubbleSort(Imagem imagens[], int n) {
    int i, j;
    Imagem temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (imagens[j].codigo_alerta > imagens[j+1].codigo_alerta) {
                temp = imagens[j];
                imagens[j] = imagens[j+1];
                imagens[j+1] = temp;
            }
        }
    }
}
