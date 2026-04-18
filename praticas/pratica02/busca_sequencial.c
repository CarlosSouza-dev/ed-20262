#include <stdio.h>
#define TAMANHO 100

int busca_sequencial(int vet[], int tamanho, int alvo){
    for (int i = 0; i < tamanho; i++){
        if (vet[i] == alvo){
            return vet[i];
        }        
    }
    return -1;
}

int main(){
    int alvo, resultado;
    int vetor[TAMANHO];
    
    for (int i = 0; i < TAMANHO; i++){
        vetor[i] = i + 1;    
    }

    printf("Entre com um numero para buscar (ate 100): " );
    scanf("%d", &alvo);

    resultado = busca_sequencial(vetor, TAMANHO, alvo);

    if (resultado != -1){
        printf("A busca pelo valor %d resultou em: %d\n", alvo, resultado);
    } else{
        printf("Aviso: O valor %d nao esta presente no vetor.\n", alvo);
    }
    
        return 0;
}