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

*Lista lista_criar(){
    Lista *l = (Lista*)
}