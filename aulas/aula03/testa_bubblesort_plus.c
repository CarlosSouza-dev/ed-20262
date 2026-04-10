#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"


#define TAMANHO 1000000

int main ()
{
    int vetor [TAMANHO];
    for (int i = 0; i < TAMANHO; i++) 
    {
        vetor [i] = rand();
    }
    
    printf("Vetor antes de ordenar\n");
    imprimir_vetor (vetor, TAMANHO);
    
    clock_t inicio = clock();
    bubble_sort (vetor , TAMANHO);
    clock_t termino = clock();
    float duracao = (float)(termino - inicio) / CLOCKS_PER_SEC;

    printf ("Vetor depois de ordenar em %fs\n", duracao);
    imprimir_vetor (vetor, TAMANHO);
    
}

// Copilar: gcc ordenacao.c testa_bubblesort_plus.c -o testa_bubblesort_plus.out
// Executar: ./testa_bubblesort_plus.out