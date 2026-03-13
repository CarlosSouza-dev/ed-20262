#include <stdio.h>
float calcula_imc(float peso, float altura){
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

    imc = calcula_imc(1.75f, 50.0f);
    printf("altura = 1.75, peso = 0, imc = %.1f => %i\n", imc, imc < 18.5);

    imc = calcula_imc(1.75f, 65.0f);
    printf("altura = 1.75, peso = 65.0, imc = %.1f => %i\n", imc, imc >= 18.5 || imc <= 24.9);

    imc = calcula_imc(1.75f, 65.0f);
    printf("altura = 1.75, peso = 65.0, imc = %.1f => %i\n", imc, imc >= 25.0 || imc <= 29.9);

    return 0;
}