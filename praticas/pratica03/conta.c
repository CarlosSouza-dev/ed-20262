#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

struct conta_t {
    int numero;
    double saldo;
};

Conta conta_criar(int numero) {
    Conta c = (Conta) malloc(sizeof(struct conta_t));
    if (c != NULL) { 
        c->numero = numero;
        c->saldo = 0.0; 
    }
    return c;
}
void conta_depositar(Conta c, double valor) {
    if (c != NULL && valor > 0) {
        c->saldo += valor;
    }
}

int conta_sacar(Conta c, double valor) {
    if (c != NULL && valor > 0 && c->saldo >= valor) {
        c->saldo -= valor;
        return 1;
    }
    return 0;
}

double conta_ver_saldo(Conta c) {
    if (c != NULL) {
        return c->saldo;
    }
    return -1.0;
}

void conta_destruir(Conta c) {
    if (c != NULL) {
        free(c);
    }
}