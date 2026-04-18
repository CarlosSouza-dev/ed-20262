#include <stdio.h>
#include "conta.h"

int main() {
    printf("Teste do TDA Conta Bancaria\n\n");

    Conta minha_conta = conta_criar(12345);
    if (minha_conta == NULL) {
        printf("Erro ao criar a conta!\n");
        return 1;
    }
    printf("Conta criada com sucesso.\n");
    printf("Saldo inicial: R$ %.2f\n\n", conta_ver_saldo(minha_conta));

    printf("Depositando R$ 500.00...\n");
    conta_depositar(minha_conta, 500.0);
    printf("Saldo apos deposito: R$ %.2f\n\n", conta_ver_saldo(minha_conta));

    printf("Tentando sacar R$ 150.00...\n");
    if (conta_sacar(minha_conta, 150.0)) {
        printf(" -> Saque aprovado!\n");
    } else {
        printf(" -> Saque negado!\n");
    }
    printf("Saldo apos saque: R$ %.2f\n\n", conta_ver_saldo(minha_conta));

    printf("Tentando sacar R$ 600.00...\n");
    if (conta_sacar(minha_conta, 600.0)) {
        printf(" -> Saque aprovado\n");
    } else {
        printf(" -> Saque negado. Saldo insuficiente.\n");
    }
    printf("Saldo final: R$ %.2f\n\n", conta_ver_saldo(minha_conta));

    conta_destruir(minha_conta);
    printf("Memoria da conta liberada com sucesso.\n");
    
    system("pause");
    
    return 0;
}