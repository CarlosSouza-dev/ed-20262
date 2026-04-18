#include "selecao.h"

int busca_sequencial(int v[], int n, int valor){
    for(int i = 0; i < n; i++){
        if (v[i] == valor){
            return 0;
        }
    }
    return -1;
}