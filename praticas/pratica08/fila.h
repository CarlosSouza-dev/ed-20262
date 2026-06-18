#ifndef FILA_H
#define FILA_H

typedef struct fila_t Fila;

Fila* fila_criar();
int fila_enfileirar(Fila *f, int valor);
int fila_desenfileirar(Fila *f);
int fila_inicio(Fila *f, int *valor); 
int fila_esta_vazia(Fila *f);
void fila_exibir(Fila *f);
void fila_destruir(Fila *f);

#endif