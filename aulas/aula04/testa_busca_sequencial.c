#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAMANHO 10

int main(){
    int vetor[TAMANHO];
    for (int i = 0; i < TAMANHO; i++){
        vetor[i] = rand() % TAMANHO;
    }
    printf("\n");
    int valor;
    printf("Entre com um numero para buscar: " );
    scanf("%i", &valor);

    int achou = busca_sequencial(vetor, TAMANHO, valor);
    printf("A busca pelo valor %i resultou em %i\n", valor, achou);
    return 0;
}

clock_t inicio = clock();
int achou = busca_sequencial(vetor, TAMANHO, valor);
clock_t