#include "selecao.h"

int linear_search(int v[], int n, int alvo) {
    for (int i = 0; i < n; i++) {
        if (v[i] == alvo) return i;
    }
    return -1;
}

static void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

static int particionar(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio;
    for (int j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            troca(&v[i], &v[j]);
            i++;
        }
    }
    troca(&v[i], &v[fim]);
    return i;
}

int quick_select(int v[], int inicio, int fim, int k) {
    if (inicio == fim) return v[inicio];

    int p = particionar(v, inicio, fim);

    if (k == p) {
        return v[p];
    } else if (k < p) {
        return quick_select(v, inicio, p - 1, k);
    } else {
        return quick_select(v, p + 1, fim, k);
    }
}