#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "imagem.h"
#include "bubble_sort.h"
#include "tim_sort.h"
#include "merge_sort.h"
#include "radix_sort.h"
#include "heap_sort.h"
#include "red_black_sort.h"
#include "gerar_dados.h"

#define MAX_IMAGENS 1000

//Bubble Sort, Tim Sort, Merge Sort, Radix Sort, Heap Sort e Red-Black Tree Sort.

void ler_dados(Imagem imagens[], int *n);
void escrever_dados(Imagem imagens[], int n, const char* filename);

int main() {
    srand(time(NULL));  // Inicializa a semente para geração aleatória
    Imagem imagens[MAX_IMAGENS];
    int n;
    int escolha;

    printf("Escolha a fonte dos dados:\n");
    printf("1. Dados externos (arquivo txt)\n");
    printf("2. Dados internos (geração aleatória)\n");
    scanf("%d", &escolha);

    if (escolha == 1) {
        ler_dados(imagens, &n);
    } else if (escolha == 2) {
        n = MAX_IMAGENS;
        gerar_dados_internos(imagens, n);
        printf("Quantidade de linhas aleatórias geradas: %d\n", n);
    } else {
        printf("Opção inválida!\n");
        return 1;
    }

    // Medir e gravar o tempo de execução para Bubble Sort
    clock_t start = clock();
    bubbleSort(imagens, n);
    clock_t end = clock();
    double bubbleTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo gasto no Bubble Sort: %f segundos\n", bubbleTime);

    // Medir e gravar o tempo de execução para Tim Sort
    start = clock();
    timSort(imagens, n);
    end = clock();
    double timTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo gasto no Tim Sort: %f segundos\n", timTime);

    // Medir e gravar o tempo de execução para Radix Sort
    start = clock();
    radixSort(imagens, n);
    end = clock();
    double radixTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo gasto no Radix Sort: %f segundos\n", radixTime);

    // Medir e gravar o tempo de execução para Merge Sort
    start = clock();
    mergeSort(imagens, 0, n - 1);
    end = clock();
    double mergeTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo gasto no Merge Sort: %f segundos\n", mergeTime);

    // Medir e gravar o tempo de execução para Heap Sort
    start = clock();
    heapSort(imagens, n);
    end = clock();
    double heapTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo gasto no Heap Sort: %f segundos\n", heapTime);

    // Medir e gravar o tempo de execução para Red-Black Tree Sort
    start = clock();
    redBlackSort(imagens, n);
    end = clock();
    double redBlackTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo gasto no Red-Black Tree Sort: %f segundos\n", redBlackTime);

    // Escrever os dados ordenados para o arquivo de saída apropriado
    if (escolha == 1) {
        escrever_dados(imagens, n, "ordenacao_saida_externo.txt");
    } else {
        escrever_dados(imagens, n, "ordenacao_saida_interno.txt");
    }


    return 0;
}

void ler_dados(Imagem imagens[], int *n) {
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    int i = 0;
    while (fscanf(arquivo, "%d,%f,%10s,%10s,%2s,%49[^\n]", 
        &imagens[i].codigo_alerta, 
        &imagens[i].area, 
        imagens[i].data_inicio, 
        imagens[i].data_fim, 
        imagens[i].estado, 
        imagens[i].municipio) != EOF) {
        i++;
    }
    *n = i;
    fclose(arquivo);
}

void escrever_dados(Imagem imagens[], int n, const char* filename) {
    FILE *arquivo = fopen(filename, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(arquivo, "%d,%.2f,%s,%s,%s,%s\n", imagens[i].codigo_alerta, imagens[i].area, imagens[i].data_inicio, imagens[i].data_fim, imagens[i].estado, imagens[i].municipio);
    }
    fclose(arquivo);
}
