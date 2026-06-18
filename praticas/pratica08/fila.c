#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

struct fila_t {
    no_t *inicio;
    no_t *fim;
};

Fila* fila_criar() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

int fila_esta_vazia(Fila *f) {
    if (f == NULL) return 1;
    return (f->inicio == NULL);
}

int fila_enfileirar(Fila *f, int valor) {
    if (f == NULL) return 0;

    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0;

    novo->valor = valor;
    novo->proximo = NULL;

    if (fila_esta_vazia(f)) {
        f->inicio = novo;
    } else {

        f->fim->proximo = novo;
    }

    f->fim = novo;
    return 1;
}

int fila_desenfileirar(Fila *f) {
    if (f == NULL || fila_esta_vazia(f)) return 0;

    no_t *lixo = f->inicio;
    
    f->inicio = lixo->proximo;
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    free(lixo);
    return 1;
}

int fila_inicio(Fila *f, int *valor) {
    if (f == NULL || fila_esta_vazia(f)) return 0;
    
    *valor = f->inicio->valor; 
    return 1;
}

void fila_exibir(Fila *f) {
    if (f == NULL || fila_esta_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    
    no_t *atual = f->inicio;
    printf("Inicio -> [ ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("] <- Fim\n");
}

void fila_destruir(Fila *f) {
    if (f != NULL) {
        no_t *atual = f->inicio;
        while (atual != NULL) {
            no_t *temp = atual;      
            atual = atual->proximo;  
            free(temp);              
        }
        free(f);
    }
}