#include <stdio.h>
#include <windows.h>
float calcula_media_aritmetica(int n){
    float soma = 0.0f;
    float vet[100];
    for (int i = 0; i < n; i++){
        printf("n = %d, informe o %dº número: ", n, i + 1);
            scanf("%f", &vet[i]);
            soma += vet[i];
        }
    return soma / n;
    }
 
int main()
{
    SetConsoleOutputCP(65001);
    
    float media = calcula_media_aritmetica(3);
    printf("A média aritmética é: %.2f\n", media);   
    printf("\n");

    media = calcula_media_aritmetica(4);
    printf("A média aritmética é: %.2f\n", media);   
    printf("\n");
    
    media = calcula_media_aritmetica(5);
    printf("A média aritmética é: %.2f\n", media);   
    printf("\n");

    media = calcula_media_aritmetica(6);
    printf("A média aritmética é: %.2f\n", media);   

    return 0;
}