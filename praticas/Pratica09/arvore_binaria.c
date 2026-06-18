#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

// Definição do Nó da Árvore Binária
typedef struct no_t {
    int valor;
    struct no_t *esquerda;
    struct no_t *direita;
} no_t;

struct arvore_t {
    no_t *raiz;
};

// Cria uma árvore vazia
Arvore* arvore_criar() {
    Arvore *a = (Arvore*) malloc(sizeof(Arvore));
    if (a != NULL) {
        a->raiz = NULL;
    }
    return a;
}

// Verifica se a árvore está vazia
int arvore_esta_vazia(Arvore *a) {
    if (a == NULL) return 1;
    return (a->raiz == NULL);
}

// Função recursiva para inserir o nó no local correto
no_t* inserir_recursivo(no_t *raiz_atual, int valor, int *sucesso) {
    // Caso base: encontrou um espaço vazio, cria o nó aqui!
    if (raiz_atual == NULL) {
        no_t *novo = (no_t*) malloc(sizeof(no_t));
        if (novo == NULL) {
            *sucesso = 0;
            return NULL;
        }
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        *sucesso = 1;
        return novo;
    }

    // Se o valor for menor, tenta inserir na subárvore da esquerda
    if (valor < raiz_atual->valor) {
        raiz_atual->esquerda = inserir_recursivo(raiz_atual->esquerda, valor, sucesso);
    } 
    // Se o valor for maior, tenta inserir na subárvore da direita
    else if (valor > raiz_atual->valor) {
        raiz_atual->direita = inserir_recursivo(raiz_atual->direita, valor, sucesso);
    } 
    // Se for igual, o valor já existe
    else {
        *sucesso = 0;
    }

    return raiz_atual;// Retorna o nó atual para manter a árvore conectada
}

// Percurso Pré-ordem (Raiz -> Esquerda -> Direita)
void pre_ordem_recursivo(no_t *raiz_atual) {
    if (raiz_atual != NULL) {
        printf("%d ", raiz_atual->valor);
        pre_ordem_recursivo(raiz_atual->esquerda);
        pre_ordem_recursivo(raiz_atual->direita);
    }
}

// Percurso Em-ordem (Esquerda -> Raiz -> Direita)
void em_ordem_recursivo(no_t *raiz_atual) {
    if (raiz_atual != NULL) {
        em_ordem_recursivo(raiz_atual->esquerda);
        printf("%d ", raiz_atual->valor);
        em_ordem_recursivo(raiz_atual->direita);
    }
}

// Percurso Pós-ordem (Esquerda -> Direita -> Raiz)
void pos_ordem_recursivo(no_t *raiz_atual) {
    if (raiz_atual != NULL) {
        pos_ordem_recursivo(raiz_atual->esquerda);
        pos_ordem_recursivo(raiz_atual->direita);
        printf("%d ", raiz_atual->valor);
    }
}

// Função recursiva para dar free em todos os nós
void destruir_recursivo(no_t *raiz_atual) {
    if (raiz_atual != NULL) {
        destruir_recursivo(raiz_atual->esquerda);
        destruir_recursivo(raiz_atual->direita);
        free(raiz_atual);
    }
}

int arvore_inserir(Arvore *a, int valor) {
    if (a == NULL) return 0;
    int sucesso = 0;
    
    a->raiz = inserir_recursivo(a->raiz, valor, &sucesso);
    return sucesso;
}

void arvore_exibir_pre_ordem(Arvore *a) {
    if (a == NULL || arvore_esta_vazia(a)) { printf("Arvore vazia.\n"); return; }
    printf("Pre-ordem: [ ");
    pre_ordem_recursivo(a->raiz);
    printf("]\n");
}

void arvore_exibir_em_ordem(Arvore *a) {
    if (a == NULL || arvore_esta_vazia(a)) { printf("Arvore vazia.\n"); return; }
    printf("Em-ordem:  [ ");
    em_ordem_recursivo(a->raiz);
    printf("]\n");
}

void arvore_exibir_pos_ordem(Arvore *a) {
    if (a == NULL || arvore_esta_vazia(a)) { printf("Arvore vazia.\n"); return; }
    printf("Pos-ordem: [ ");
    pos_ordem_recursivo(a->raiz);
    printf("]\n");
}

void arvore_destruir(Arvore *a) {
    if (a != NULL) {
        destruir_recursivo(a->raiz);
        free(a); // Libera a estrutura de controle
    }
}