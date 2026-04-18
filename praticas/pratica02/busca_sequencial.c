#include <stdio.h>
#define TAMANHO 100

int busca_sequencial(int vet[], int tamanho, int alvo){
    for (int i = 0; i < tamanho; i++){
        if (vet[i] == alvo){
            return i;
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
/*
Melhor Caso: O(1) melhor cenário possível ocorre quando o número que o usuário digitou está exatamente na primeira posição do vetor (índice 0). O algoritmo faz apenas $1$ comparação, encontra o valor, e o loop é encerrado imediatamente. O tempo de execução é constante, independentemente do tamanho do vetor.
Pior Caso: O(n) pior cenário ocorre em duas situações: quando o número procurado é o último elemento do vetor, ou quando ele não existe no vetor. Em ambos os casos, o algoritmo é forçado a percorrer todas as n posições. O tempo de execução cresce linearmente de forma proporcional ao tamanho do vetor. Se o vetor tivesse 1 milhão de posições, ele faria 1 milhão de comparações.
*/