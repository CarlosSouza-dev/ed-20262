#include <stdio.h>
float calcula_media_aritmetica(int n, float valores[]){
    float soma = 0.0f;

    for (int i = 0; i < n; i++){
            soma += valores[i];
        }

    return soma / n;
    }
 
int main(){
    
    float media = calcula_media_aritmetica(5, (float[]){7.0, 8.0, 6.0, 10.0, 70,0});
    printf("A media aritmetica e: %.2f\n", media);   
    printf("\n");

    media = calcula_media_aritmetica(6, (float[]){1.0, 81.0, 60.0, 10.0, 70,0});
    printf("A media aritmetica e: %.2f\n", media);   
    printf("\n");
    
    media = calcula_media_aritmetica(5, (float[]){2.0, 5.0, 45.0, 142.0, 7.0});
    printf("A media aritmetica e: %.2f\n", media);   
    printf("\n");
 

    return 0;
}