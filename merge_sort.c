#include "merge_sort.h"

void merge(Imagem imagens[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Imagem L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = imagens[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = imagens[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].codigo_alerta <= R[j].codigo_alerta) {
            imagens[k] = L[i];
            i++;
        } else {
            imagens[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        imagens[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        imagens[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Imagem imagens[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(imagens, left, mid);
        mergeSort(imagens, mid + 1, right);
        merge(imagens, left, mid, right);
    }
}