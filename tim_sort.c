#include "tim_sort.h"

#define RUN 32

void insertionSort(Imagem arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        Imagem temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j].codigo_alerta > temp.codigo_alerta) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void mergeTim(Imagem arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    Imagem left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < len1 && j < len2) {
        if (left[i].codigo_alerta <= right[j].codigo_alerta) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void timSort(Imagem arr[], int n) {
    for (int i = 0; i < n; i+=RUN)
        insertionSort(arr, i, (i+31) < (n-1) ? (i+31) : (n-1));
    for (int size = RUN; size < n; size = 2*size) {
        for (int left = 0; left < n; left += 2*size) {
            int mid = left + size - 1;
            int right = (left + 2*size - 1 < n - 1) ? (left + 2*size - 1) : (n - 1);
            mergeTim(arr, left, mid, right);
        }
    }
}
