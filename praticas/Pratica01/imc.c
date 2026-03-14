#include <stdio.h>
float calcula_imc(float altura, float peso){
    if (altura <= 0.0f || peso <= 0.0f){
        return 0.0f;
    }
    
    return peso / (altura *altura);
}
int main()
{
    
    float imc = 0.0f;
    imc = calcula_imc(0.0f, 50.0f);
    printf("altura = 0, peso = 50, imc = %.1f => %i\n", imc, imc == 0);
    
    imc = calcula_imc(1.75f, 0.0f);
    printf("altura = 1.75, peso = 0, imc = %.1f => %i\n", imc, imc == 0);

    imc = calcula_imc(1.75f, .0f); // abaixo do peso
    printf("altura = 1.75, peso = 50, imc = %.1f => %i\n", imc, imc < 18.5);

    imc = calcula_imc(1.75f, 65.0f); //normal
    printf("altura = 1.75, peso = 65.0, imc = %.1f => %i\n", imc, imc >= 18.5 || imc <= 24.9);

    imc = calcula_imc(1.75f, 85.0f); //sobrepeso
    printf("altura = 1.75, peso = 85.0, imc = %.1f => %i\n", imc, imc >= 25.0 || imc <= 29.9);

    imc = calcula_imc(1.75f, 95.0f); //obesidade
    printf("altura = 1.75, peso = 95.0, imc = %.1f => %i\n", imc, imc >= 30.0);

    return 0;
}