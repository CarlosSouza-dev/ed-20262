#include <stdio.h>
#include "tabela_hash.h"

int main() {
    printf("--- Teste do TAD Tabela Hash (Encadeamento Separado) ---\n\n");

    // Criando uma tabela com 5 gavetas
    TabelaHash *minha_tabela = hash_criar(5);
    if (minha_tabela == NULL) {
        printf("Erro ao criar a tabela hash.\n");
        return 1;
    }

    /* 1. Inserindo valores (Teste de colisão)
    Se a tabela tem tamanho 5, os números 10, 15, 20 e 25 
    todos deixarão resto 0 na divisão por 5. 
    Ou seja: vão gerar COLISÃO na gaveta [0] */
    printf("Inserindo elementos (10, 15, 20, 25, 7, 12, 14)...\n");
    hash_inserir(minha_tabela, 10);
    hash_inserir(minha_tabela, 15);
    hash_inserir(minha_tabela, 20);
    hash_inserir(minha_tabela, 25);
    
    // Esses vão para outras gavetas (7 % 5 = 2), (12 % 5 = 2), (14 % 5 = 4)
    hash_inserir(minha_tabela, 7);
    hash_inserir(minha_tabela, 12);
    hash_inserir(minha_tabela, 14);

    printf("\n");
    hash_exibir(minha_tabela);

    // 2. Buscando valores
    printf("\n--- Testes de Busca ---\n");
    printf("Buscando o 15 (deve gerar colisao e achar): %s\n", hash_buscar(minha_tabela, 15) ? "Encontrado" : "Nao Encontrado");
    printf("Buscando o 99 (nao existe): %s\n", hash_buscar(minha_tabela, 99) ? "Encontrado" : "Nao Encontrado");

    // 3. Removendo valores
    printf("\n--- Testes de Remocao ---\n");
    printf("Removendo o 15 (meio da colisao)...\n");
    hash_remover(minha_tabela, 15);
    
    printf("Removendo o 14 (gaveta 4)...\n");
    hash_remover(minha_tabela, 14);

    printf("\nEstado apos as remocoes:\n");
    hash_exibir(minha_tabela);

    // Limpeza final
    hash_destruir(minha_tabela);
    printf("\nMemoria liberada com sucesso. Fim do programa.\n");

    return 0;
}