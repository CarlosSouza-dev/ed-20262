#include <stdio.h>

int main()
{
    int peso;
    int altura;
    int IMC;
    printf("Digite seu peso: \n");
    scanf("%.2f", &peso);
    printf("Digite sua altura em metros: \n");
    scanf("%.2f", &altura);
    IMC = peso/altura^2;
    printf("Seu IMC: %.2f \n", IMC);
    
    return 0;
}