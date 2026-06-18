#include <stdio.h>
#include "pilha.h"

int main() {
    printf("--- Teste do TAD Pilha (Stack) ---\n");

    Pilha *minha_pilha = pilha_criar();
    if (minha_pilha == NULL) {
        printf("Erro ao criar a pilha.\n");
        return 1;
    }

    // 1. Testando Empilhar
    printf("\nEmpilhando 10, 20 e 30...\n");
    pilha_empilhar(minha_pilha, 10);
    pilha_empilhar(minha_pilha, 20);
    pilha_empilhar(minha_pilha, 30);
    pilha_exibir(minha_pilha);

    // 2. Consultando o Topo
    int valor_topo;
    if (pilha_topo(minha_pilha, &valor_topo)) {
        printf("\nO valor no topo atualmente e: %d\n", valor_topo);
    }

    // 3. Testando Desempilhar
    printf("\nDesempilhando o topo...\n");
    pilha_desempilhar(minha_pilha);
    pilha_exibir(minha_pilha);

    // Verificando o topo novamente
    if (pilha_topo(minha_pilha, &valor_topo)) {
        printf("Apos desempilhar, o novo topo e: %d\n", valor_topo);
    }

    // 4. Esvaziando a pilha
    printf("\nDesempilhando todos os elementos restantes...\n");
    pilha_desempilhar(minha_pilha); // Tira o 20
    pilha_desempilhar(minha_pilha); // Tira o 10
    pilha_exibir(minha_pilha);

    // 5. Tentando desempilhar de uma pilha vazia
    if (!pilha_desempilhar(minha_pilha)) {
        printf("Correto: A funcao impediu o desempilhamento de uma pilha vazia.\n");
    }

    // Limpeza da memória
    pilha_destruir(minha_pilha);
    printf("\nMemoria liberada com sucesso. Fim do programa.\n");

    return 0;
}