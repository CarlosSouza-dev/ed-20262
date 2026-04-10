#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define TAMANHO 10

int main() {
    clock_t tempo_inicial, tempo_final;
    double duracao;

    int vetor[TAMANHO] = {5, 11, 4, 1, 17, 8, 6, 47, 51, 2};

    printf("Vetor antes de ordenar:\n");
    imprimir_vetor(vetor, TAMANHO);

    tempo_inicial = clock();
    bubble_sort(vetor, TAMANHO);
    tempo_final = clock();

    printf("Vetor depois de ordenar:\n");
    imprimir_vetor(vetor, TAMANHO);

    duracao = ((double)(tempo_final - tempo_inicial)) / CLOCKS_PER_SEC;
    printf("Vetor depois de ordenar em %f segundos\n", duracao);

    return 0;
}

// Copilar TUDO: gcc *.c -lm -o a.out
// Executar: ./a.out

// Copilar: gcc ordenacao.c testa_bubblesort.c -o testa_bubblesort.out
// Executar: ./testa_bubblesort.out