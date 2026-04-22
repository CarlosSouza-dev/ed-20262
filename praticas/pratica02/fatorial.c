#include <stdio.h>

unsigned long long fatorial_rep(int num){
    unsigned long long resultado = 1;
    if (num < 0 || num > 20){
        printf("Número negativo ou grande demais\n");
    }
    if (num == 0 || num == 1){
        return 1;
    }
    for(int i = 1; i <= num; i++){
        resultado *= i;
    }
    return resultado;
}

unsigned long long fatorial_rec(int num){
    if (num < 0 || num > 20){
        printf("Número negativo ou grande demais\n");
    }
    if (num == 0 || num == 1){
        return 1;
    }
    return num * fatorial_rec(num - 1);
}

int main(){

    int resposta_rep = fatorial_rep(5);
    int resposta_rec = fatorial_rec(5);

    printf("Por repeticao:\n");
    printf("fatorial de 5: %llu\n", resposta_rep);

    printf("Por recursividade:\n");
    printf("fatorial de 5: %llu\n\n", resposta_rec);

    printf("--- Complexidade Assintotica ---\n");
    
    printf("1. Abordagem Iterativa (Repeticao):\n");
    printf("   - Complexidade de Tempo: O(n)\n");
    printf("   - Complexidade de Espaco: O(1)\n\n");

    printf("2. Abordagem Recursiva:\n");
    printf("   - Complexidade de Tempo: O(n)\n");
    printf("   - Complexidade de Espaco: O(n)\n");
    return 0;
}