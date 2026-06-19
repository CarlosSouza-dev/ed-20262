#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

// Definição do Nó
typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

// Estrutura principal da Tabela Hash
struct hash_t {
    no_t **tabela;
    int tamanho;
};

static int funcao_hash(int valor, int tamanho) {
    int chave = valor % tamanho;
    return (chave < 0) ? -chave : chave;
}

// Cria e inicializa a Tabela Hash
TabelaHash* hash_criar(int tamanho) {
    if (tamanho <= 0) return NULL;

    TabelaHash *h = (TabelaHash*) malloc(sizeof(TabelaHash));
    if (h != NULL) {
        h->tamanho = tamanho;
        // Aloca o vetor de gavetas
        h->tabela = (no_t**) malloc(tamanho * sizeof(no_t*));
        
        // Inicializa todas as gavetas como vazias (NULL)
        for (int i = 0; i < tamanho; i++) {
            h->tabela[i] = NULL;
        }
    }
    return h;
}

// Verifica se toda a tabela hash está completamente vazia
int hash_esta_vazia(TabelaHash *h) {
    if (h == NULL) return 1;
    
    for (int i = 0; i < h->tamanho; i++) {
        if (h->tabela[i] != NULL) {
            return 0;
        }
    }
    return 1;
}

// Insere um valor na tabela resolvendo colisões com encadeamento
int hash_inserir(TabelaHash *h, int valor) {
    if (h == NULL) return 0;

    int indice = funcao_hash(valor, h->tamanho);

    // Cria o novo nó
    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0;
    
    novo->valor = valor;
    
    novo->proximo = h->tabela[indice];
    h->tabela[indice] = novo;

    return 1;
}

// Busca um valor (O(1) na melhor das hipóteses, ou O(n) na lista de colisão)
int hash_buscar(TabelaHash *h, int valor) {
    if (h == NULL) return 0;

    int indice = funcao_hash(valor, h->tamanho);
    
    no_t *atual = h->tabela[indice];
    while (atual != NULL) {
        if (atual->valor == valor) return 1;
        atual = atual->proximo;
    }
    
    return 0;
}

// Remove um valor da tabela
int hash_remover(TabelaHash *h, int valor) {
    if (h == NULL) return 0;

    int indice = funcao_hash(valor, h->tamanho);
    
    no_t *atual = h->tabela[indice];
    no_t *anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return 0;

    // Lógica de remoção de lista encadeada simples
    if (anterior == NULL) {
        
        h->tabela[indice] = atual->proximo;
    } else {
        
        anterior->proximo = atual->proximo;
    }

    free(atual);
    return 1;
}

// Exibe a tabela no formato de matriz/listas
void hash_exibir(TabelaHash *h) {
    if (h == NULL || hash_esta_vazia(h)) {
        printf("Tabela Hash Vazia.\n");
        return;
    }

    printf("--- Estado da Tabela Hash ---\n");
    for (int i = 0; i < h->tamanho; i++) {
        printf("Gaveta [%02d]: ", i);
        no_t *atual = h->tabela[i];
        
        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}

// Libera toda a memória (nós e o vetor principal)
void hash_destruir(TabelaHash *h) {
    if (h != NULL) {
        for (int i = 0; i < h->tamanho; i++) {
            no_t *atual = h->tabela[i];
            while (atual != NULL) {
                no_t *temp = atual;
                atual = atual->proximo;
                free(temp);
            }
        }
        free(h->tabela);
        free(h);
    }
}