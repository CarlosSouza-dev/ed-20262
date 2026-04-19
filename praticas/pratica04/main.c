#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define TAMANHO 100

void copiar_vetor(int origem[], int destino[], int n) {
    for(int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

int main() {
    int vetor_original[TAMANHO];
    int vetor_teste[TAMANHO];
    clock_t inicio, termino;
    float duracao;

    srand(time(NULL));

    for(int i = 0; i < TAMANHO; i++) {
        vetor_original[i] = rand() % 10000; 
    }

    printf("=== Teste de Algoritmos de Ordenacao (%d elementos) ===\n\n", TAMANHO);

    // 1. Teste do Bubble Sort

    copiar_vetor(vetor_original, vetor_teste, TAMANHO);
    inicio = clock();
    bubble_sort(vetor_teste, TAMANHO);
    termino = clock();
    duracao = (float)(termino - inicio) / CLOCKS_PER_SEC;
    printf("Tempo Bubble Sort   : %f s\n", duracao);

    // 2. Teste do Selection Sort

    copiar_vetor(vetor_original, vetor_teste, TAMANHO);
    inicio = clock();
    selection_sort(vetor_teste, TAMANHO);
    termino = clock();
    duracao = (float)(termino - inicio) / CLOCKS_PER_SEC;
    printf("Tempo Selection Sort: %f s\n", duracao);

    // 3. Teste do Quick Sort

    copiar_vetor(vetor_original, vetor_teste, TAMANHO);
    inicio = clock();
    quick_sort(vetor_teste, 0, TAMANHO - 1);
    termino = clock();
    duracao = (float)(termino - inicio) / CLOCKS_PER_SEC;
    printf("Tempo Quick Sort    : %f s\n", duracao);

    return 0;
}