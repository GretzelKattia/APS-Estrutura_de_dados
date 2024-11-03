#include <stdio.h>
#include <stdlib.h>
#include "heap_sort.h"

void heapify(Imagem arr[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].codigo_alerta > arr[largest].codigo_alerta)
        largest = left;

    if (right < n && arr[right].codigo_alerta > arr[largest].codigo_alerta)
        largest = right;

    if (largest != i) {
        Imagem temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(Imagem arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        Imagem temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
