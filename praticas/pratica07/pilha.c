#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

struct pilha_t {
    no_t *topo;
};

// Cria uma pilha vazia
Pilha* pilha_criar() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    if (p != NULL) {
        p->topo = NULL;
    }
    return p;
}

// Verifica se há elementos na pilha
int pilha_esta_vazia(Pilha *p) {
    if (p == NULL) return 1;
    return (p->topo == NULL);
}

// Empilhar
int pilha_empilhar(Pilha *p, int valor) {
    if (p == NULL) return 0;

    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0;

    novo->valor = valor;
    
    novo->proximo = p->topo; 
    
    p->topo = novo; 
    
    return 1;
}

// Desempilhar
int pilha_desempilhar(Pilha *p) {
    if (p == NULL || pilha_esta_vazia(p)) return 0;

    no_t *lixo = p->topo;
    
    p->topo = lixo->proximo;
    
    free(lixo); // Libera o nó removido da memória
    return 1;
}

// Consulta o elemento do topo sem removê-lo
int pilha_topo(Pilha *p, int *valor) {
    if (p == NULL || pilha_esta_vazia(p)) return 0;
    
    *valor = p->topo->valor; 
    return 1;
}

void pilha_exibir(Pilha *p) {
    if (p == NULL || pilha_esta_vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    
    no_t *atual = p->topo;
    printf("Topo -> [ ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("] -> Base\n");
}

// Libera toda a memória alocada para a pilha e seus nós
void pilha_destruir(Pilha *p) {
    if (p != NULL) {
        no_t *atual = p->topo;
        while (atual != NULL) {
            no_t *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
        free(p);
    }
}