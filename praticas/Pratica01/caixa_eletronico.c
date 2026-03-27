#include <stdio.h>

typedef struct
{
    int n200; 
    int n100;
    int n50;
    int n20;
    int n10;
    int n5;
    int n2;
    int possivel;
} saque;

saque calcular_notas(int valor) {
    saque s = {0, 0, 0, 0, 0, 0, 0, 1};
    if(valor <= 0 || valor > 1000){ 
        s.possivel = 0;
        return s;
    }
    
    if (valor == 1 || valor == 3){
        s.possivel = 0;
        return s;
    }
    
    if (valor % 2 != 0){
        s.n5 = 1;
        valor -= 5;
    }
    
    s.n200 = valor / 200; valor %= 200;
    s.n100 = valor / 100; valor %= 100;
    s.n50 = valor / 50; valor %= 50;
    s.n20 = valor / 20; valor %= 20;
    s.n10 = valor / 10; valor %= 10;
    s.n2 = valor / 2; valor %= 2;
    return s;
}

void exibir_saque(saque s, int valor_original){
    if (!s.possivel){
        printf("\nErro, Nao e possivel sacar R$ %d exatos com as notas disponiveis.\n", valor_original);
        return;
    }
    
    printf("\n--- Resultado do Saque: R$ %d ---\n", valor_original);
    if (s.n200 > 0) printf("%d nota(s) de R$ 200\n", s.n200);
    if (s.n100 > 0) printf("%d nota(s) de R$ 100\n", s.n100);
    if (s.n50 > 0) printf("%d nota(s) de R$ 50\n", s.n50);
    if (s.n20 > 0) printf("%d nota(s) de R$ 20\n", s.n20);
    if (s.n10 > 0) printf("%d nota(s) de R$ 10\n", s.n10);
    if (s.n5 > 0) printf("%d nota(s) de R$ 5\n", s.n5);
    if (s.n2 > 0) printf("%d nota(s) de R$ 2\n", s.n2);
    printf("----------------------------------\n");
}

int main() {
    int valor = 456;
    saque resultados = calcular_notas(valor);
    exibir_saque(resultados, valor);
    printf("\n");

    valor = 125;
    resultados = calcular_notas(valor);
    exibir_saque(resultados, valor);
    printf("\n");

    valor = 67;
    resultados = calcular_notas(valor);
    exibir_saque(resultados, valor);
    printf("\n");

    valor = 0;
    resultados = calcular_notas(valor);
    exibir_saque(resultados, valor);
    printf("\n");

    return 0;
}