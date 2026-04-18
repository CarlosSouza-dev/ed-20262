#include <stdio.h>
float calcular_potencia(float base, int expoente){
    float result = 1.0;
    for (int i = 0; i < expoente; i++){
        result = result * base;
    }

    return result;
}
int main()
{
    float potencia = calcular_potencia(1.0f, 5);
    printf("base: 1.0, expoente: 5, resultado: %.2f\n", potencia);
    
    potencia = calcular_potencia(2.0f, 4);
    printf("base: 2.0, expoente: 4, resultado: %.2f\n", potencia);
    
    potencia = calcular_potencia(3.0f, 4);
    printf("base: 3.0, expoente: 4, resultado: %.2f\n", potencia);
    
    potencia = calcular_potencia(6.0f, 2);
    printf("base: 6.0, expoente: 2, resultado: %.2f\n", potencia);
    
    potencia = calcular_potencia(10.0f, 0);
    printf("base: 10.0, expoente: 0, resultado: %.2f\n", potencia);
    return 0;
}