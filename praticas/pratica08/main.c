#include <stdio.h>
#include "fila.h"

int main() {
    printf("--- Teste do TAD Fila ---\n");

    Fila *minha_fila = fila_criar();
    if (minha_fila == NULL) {
        printf("Erro ao criar a fila.\n");
        return 1;
    }

    // 1. Testando Enfileirar 
    printf("\nEnfileirando os clientes com senhas 10, 20 e 30...\n");
    fila_enfileirar(minha_fila, 10);
    fila_enfileirar(minha_fila, 20);
    fila_enfileirar(minha_fila, 30);
    fila_exibir(minha_fila);

    // 2. Consultando o Início
    int valor_inicio;
    if (fila_inicio(minha_fila, &valor_inicio)) {
        printf("\nO proximo a ser atendido (inicio) e: %d\n", valor_inicio);
    }

    // 3. Testando Desenfileirar
    printf("\nAtendendo o primeiro da fila (desenfileirando)...\n");
    fila_desenfileirar(minha_fila);
    fila_exibir(minha_fila);

    // Verificando o novo início
    if (fila_inicio(minha_fila, &valor_inicio)) {
        printf("Agora o proximo a ser atendido e: %d\n", valor_inicio);
    }

    // 4. Esvaziando a fila
    printf("\nAtendendo os demais...\n");
    fila_desenfileirar(minha_fila);
    fila_desenfileirar(minha_fila);
    fila_exibir(minha_fila);

    // 5. Teste de segurança (desenfileirar com fila vazia)
    if (!fila_desenfileirar(minha_fila)) {
        printf("Correto: A funcao impediu tentar remover de uma fila vazia.\n");
    }

    // Limpeza da memória
    fila_destruir(minha_fila);
    printf("\nMemoria liberada com sucesso. Fim do programa.\n");

    return 0;
}