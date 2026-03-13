#include <stdio.h>
int main()
{
    float peso;
    float altura;
    float IMC;
    printf("Digite seu peso: \n");
    scanf("%f", &peso);
    printf("Digite sua altura em metros: \n");
    scanf("%f", &altura);
    IMC = peso / (altura * altura);
    printf("Seuu IMC: %.2f \n", IMC);
    
    if (IMC < 18.5){
        printf("abaixo do peso");
    } else if (18.5 <= IMC && IMC <= 24.5){
            printf("peso normal");
        } else if (25.0 <= IMC && IMC <= 29.9){
            printf("sobrepeso");
        } else if (IMC > 30.0){
            printf("obesidade");
        }

    return 0;
}