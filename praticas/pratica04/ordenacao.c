#include <stdio.h>
#include "ordenacao.h"

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble_sort(int v[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                troca(&v[i], &v[j]);
            }
        }
    }
}

void imprimir_vetor(int v[], int n)
{
    printf("[");
    for (int i = 0; i < n - 1; i++)
    {
        printf("%i, ", v[i]);
    }
    printf("%i]\n", v[n - 1]);
}

int particionar_vetor(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;
    for(int j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[fim]);
    return i + 1;
}

void quick_sort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particionar_vetor(v, inicio, fim);
        quick_sort(v, inicio, p - 1);
        quick_sort(v, p + 1, fim);
    }
}

void selection_sort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            troca(&v[i], &v[min_idx]);
        }
    }
}