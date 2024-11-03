#include <stdio.h>
#include <stdlib.h>
#include "radix_sort.h"

int getMax(Imagem arr[], int n) {
    int max = arr[0].codigo_alerta;
    for (int i = 1; i < n; i++) {
        if (arr[i].codigo_alerta > max) {
            max = arr[i].codigo_alerta;
        }
    }
    return max;
}

void countSort(Imagem arr[], int n, int exp) {
    Imagem output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++) {
        count[(arr[i].codigo_alerta / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i].codigo_alerta / exp) % 10] - 1] = arr[i];
        count[(arr[i].codigo_alerta / exp) % 10]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(Imagem arr[], int n) {
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}
