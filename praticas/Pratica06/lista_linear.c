#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no_t
{
    int valor;
    struct no_t *proximo;
    struct no_t *anterior;
}no;

struct lista_t
{
    no *primeiro;
    no *ultimo;
};

Lista* lista_criar() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    if (l != NULL){
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

int lista_esta_vazia(Lista *l){
    if (l == NULL) return 1;
    return (l->primeiro == NULL);
}

//inserir no final:

int lista_inserir(Lista *l, int valor){
    if (l == NULL) return 0;

    no *novo = (no*) malloc(sizeof(no));
    if (novo == NULL) return 0;

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = l->ultimo;

    if (lista_esta_vazia(l)){
        l->primeiro = novo;
    } else {
        l->ultimo->proximo = novo;
    }
    
    l->ultimo = novo;
    return 1;

}

int lista_buscar(Lista *l, int valor){
    if (l == NULL || lista_esta_vazia(l)) return 0;
    no *atual = l->primeiro;
    
    
    while (atual != NULL){
        if(atual->valor == valor){
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

int lista_remover(Lista *l, int valor){
    if (l == NULL || lista_esta_vazia(l)) return 0;
    
    no *atual = l->primeiro;
    
    while (atual != NULL && atual->valor != valor){
        atual = atual->proximo;
    }
    if (atual == NULL) return 0;

    // Único elemento na lista:
    if(atual->anterior == NULL && atual->proximo == NULL){
        l->primeiro == NULL;
        l->ultimo == NULL;
    }

    //1º Elemento na lista
    else if (atual->anterior == NULL){
        l->primeiro = atual->proximo;
        l->primeiro->anterior = NULL;
    }

    //Último elemento
    else if (atual->proximo == NULL){
        l->ultimo = atual->anterior;  
        l->ultimo->proximo = NULL;
    }

    //Meio da lista:
    else{
        atual->anterior->proximo = atual->proximo; 
        atual->proximo->anterior = atual->anterior;
    }

    free(atual); // Libera a memória do nó removido
    return 1;
}

void lista_exibir(Lista *l) {
    if (l == NULL || lista_esta_vazia(l)) {
        printf("Lista vazia.\n");
        return;
    }
    no *atual = l->primeiro;
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
        no *atual = l->primeiro;
        while (atual != NULL) {
            no *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
        free(l);
    }
}
