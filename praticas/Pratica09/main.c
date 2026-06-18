#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    printf("--- Teste do TAD Arvore Binaria de Busca ---\n\n");

    Arvore *minha_arvore = arvore_criar();
    if (minha_arvore == NULL) {
        printf("Erro ao criar a arvore.\n");
        return 1;
    }

    printf("Inserindo elementos (50, 30, 70, 20, 40, 60, 80)...\n\n");
    arvore_inserir(minha_arvore, 50); // Raiz
    
    arvore_inserir(minha_arvore, 30);
    arvore_inserir(minha_arvore, 70);
    
    arvore_inserir(minha_arvore, 20);
    arvore_inserir(minha_arvore, 40);
    
    arvore_inserir(minha_arvore, 60);
    arvore_inserir(minha_arvore, 80);


    // Exibindo os diferentes percursos
    printf("Analisando os percursos da arvore:\n");
    
    // Pre-ordem visita a raiz antes dos filhos
    arvore_exibir_pre_ordem(minha_arvore);
    
    // Em-ordem visita o filho esquerdo, depois a raiz, depois o direito
    arvore_exibir_em_ordem(minha_arvore);
    
    // Pós-ordem visita os filhos e a raiz por ultimo
    arvore_exibir_pos_ordem(minha_arvore);

    // Limpeza da memória
    arvore_destruir(minha_arvore);
    printf("\nMemoria liberada com sucesso. Fim do programa.\n");

    return 0;
}