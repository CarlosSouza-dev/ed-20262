#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

// Definição do Nó para Lista Encadeada Dupla
typedef struct no_t {
    int valor;
    struct no_t *anterior;
    struct no_t *proximo;
} no_t;

// Definição da estrutura principal da Lista
struct lista_t {
    no_t *primeiro;
    no_t *ultimo;
};

// Cria e inicializa a lista vazia
Lista* lista_criar() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    if (l != NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

// Verifica se a lista não contém nós
int lista_esta_vazia(Lista *l) {
    if (l == NULL) return 1;
    return (l->primeiro == NULL);
}

// Inserir no final da lista. Complexidade O(1) porque usamos o ponteiro 'ultimo'.
int lista_inserir(Lista *l, int valor) {
    if (l == NULL) return 0; // Falha (Lista não existe)

    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0; // Falha na alocação de memória

    novo->valor = valor;
    novo->proximo = NULL;      // Como é o último, não tem próximo
    novo->anterior = l->ultimo; // O anterior do novo é o atual último da lista

    if (lista_esta_vazia(l)) {
        l->primeiro = novo; // Se vazia, o novo é também o primeiro
    } else {
        l->ultimo->proximo = novo; // O antigo último aponta para o novo
    }
    
    l->ultimo = novo; // Atualiza o ponteiro de controle da lista
    return 1; // Sucesso
}

// Busca linear. Complexidade: O(n)
int lista_buscar(Lista *l, int valor) {
    if (l == NULL || lista_esta_vazia(l)) return 0;

    no_t *atual = l->primeiro;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1; // Encontrado
        }
        atual = atual->proximo;
    }
    return 0; // Não encontrado
}

// Remove o primeiro nó que encontrar com o valor especificado
int lista_remover(Lista *l, int valor) {
    if (l == NULL || lista_esta_vazia(l)) return 0;

    no_t *atual = l->primeiro;
    
    // Procura o valor
    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }

    if (atual == NULL) return 0; // Varreu tudo e não encontrou

    // Caso 1: Único elemento na lista
    if (atual->anterior == NULL && atual->proximo == NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    } 
    // Caso 2: É o primeiro elemento
    else if (atual->anterior == NULL) {
        l->primeiro = atual->proximo;
        l->primeiro->anterior = NULL;
    } 
    // Caso 3: É o último elemento
    else if (atual->proximo == NULL) {
        l->ultimo = atual->anterior;
        l->ultimo->proximo = NULL;
    } 
    // Caso 4: Está no meio da lista
    else {
        atual->anterior->proximo = atual->proximo;
        atual->proximo->anterior = atual->anterior;
    }

    free(atual); // Libera a memória do nó removido
    return 1; // Sucesso
}

// Varre a lista do começo ao fim imprimindo os valores
void lista_exibir(Lista *l) {
    if (l == NULL || lista_esta_vazia(l)) {
        printf("Lista vazia.\n");
        return;
    }
    no_t *atual = l->primeiro;
    printf("Lista: [ ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("]\n");
}

// Libera todos os nós e a própria lista para evitar vazamento de memória (Memory Leak)
void lista_destruir(Lista *l) {
    if (l != NULL) {
        no_t *atual = l->primeiro;
        while (atual != NULL) {
            no_t *temp = atual;      // Guarda a referência do atual
            atual = atual->proximo;  // Avança para o próximo
            free(temp);              // Destrói o que ficou para trás
        }
        free(l); // Destrói a estrutura de controle
    }
}