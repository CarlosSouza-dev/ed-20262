#include <stdio.h>
#include <locale.h> 
int main()
{
    setlocale(LC_ALL, "Portuguese");
    float base;
    int expoente;
    float result = 1.0;
printf("================================================== \n");
printf("Para calcular uma potência, siga as instruções: \n");
printf("================================================== \n");
printf("1- Digite uma Base: ");
scanf("%f", &base);
printf("Digite um expoente: ");
scanf("%d", &expoente);
for (int i = 0; i < expoente; i++){
    result = result * base;
}
printf("O resultado é: %.2f", result);
    return 0;
}