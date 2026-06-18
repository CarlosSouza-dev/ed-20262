#include <stdio.h>
#include "lista_linear.h"

int main() {
    printf("--- Teste do TAD Lista Encadeada Dupla ---\n");

    Lista *minha_lista = lista_criar();
    if (minha_lista == NULL) {
        printf("Erro grave: falha ao criar a lista.\n");
        return 1;
    }

    printf("\nTentando exibir lista vazia:\n");
    lista_exibir(minha_lista);

    printf("\nInserindo valores: 10, 20, 30, 40...\n");
    lista_inserir(minha_lista, 10);
    lista_inserir(minha_lista, 20);
    lista_inserir(minha_lista, 30);
    lista_inserir(minha_lista, 40);
    
    lista_exibir(minha_lista);

    printf("\nBusca Experimental:\n");
    printf("Buscando o valor 20: %s\n", lista_buscar(minha_lista, 20) ? "Encontrado" : "Nao encontrado");
    printf("Buscando o valor 50: %s\n", lista_buscar(minha_lista, 50) ? "Encontrado" : "Nao encontrado");

    printf("\nTestes de Remocao:\n");
    printf("Removendo o valor 20 (meio da lista)...\n");
    lista_remover(minha_lista, 20);
    lista_exibir(minha_lista);

    printf("Removendo o valor 10 (primeiro elemento)...\n");
    lista_remover(minha_lista, 10);
    lista_exibir(minha_lista);

    printf("Removendo o valor 40 (ultimo elemento)...\n");
    lista_remover(minha_lista, 40);
    lista_exibir(minha_lista);

    // Finalizando o ciclo de vida do programa com limpeza de heap
    lista_destruir(minha_lista);
    printf("\nMemoria liberada com sucesso. Fim do programa.\n");

    return 0;
}