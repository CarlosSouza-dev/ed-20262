#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAMANHO 100

int main() {
    int vetor[TAMANHO];
    srand(time(NULL));

    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = rand() % 500;
    }

    int alvo = vetor[rand() % TAMANHO];
    
    // Teste Busca Linear
    clock_t t1 = clock();
    int pos = linear_search(vetor, TAMANHO, alvo);
    clock_t t2 = clock();
    double tempo_linear = (double)(t2 - t1) / CLOCKS_PER_SEC;

    // Teste Quick Select
    int k = 50;
    clock_t t3 = clock();
    int valor_k = quick_select(vetor, 0, TAMANHO - 1, k);
    clock_t t4 = clock();
    double tempo_quick = (double)(t4 - t3) / CLOCKS_PER_SEC;

    printf("Resultados\n");
    printf("Busca Linear : Alvo %d encontrado na pos %d em %fs\n", alvo, pos, tempo_linear);
    printf("Quick Select : O %do menor elemento e %d em %fs\n", k+1, valor_k, tempo_quick);

    return 0;
}