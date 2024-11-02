#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fruta.h"
#include "vendas.h"  

#define MAX_FRUTAS 100

void cadastrar_fruta(Fruta* inventario[], int* total_frutas) {
    if (*total_frutas >= MAX_FRUTAS) {
        printf("Inventário cheio! Não é possível adicionar mais frutas.\n");
        return;
    }
    
    Fruta* fruta = (Fruta*)malloc(sizeof(Fruta));
    if (fruta == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    printf("Código da fruta: ");
    scanf("%d", &fruta->codigo);
    
    for (int i = 0; i < *total_frutas; i++) {
        if (inventario[i]->codigo == fruta->codigo) {
            printf("Código já cadastrado! Tente novamente.\n");
            free(fruta);
            return;
        }
    }

    printf("Nome da fruta: ");
    scanf(" %[^\n]", fruta->nome);
    printf("Quantidade: ");
    scanf("%d", &fruta->quantidade);
    printf("Preço: ");
    scanf("%f", &fruta->preco);

    inventario[(*total_frutas)++] = fruta;
    printf("Fruta cadastrada com sucesso!\n");
}

void listar_frutas(Fruta* inventario[], int total_frutas) {
    if (total_frutas == 0) {
        printf("Nenhuma fruta cadastrada.\n");
        return;
    }
    printf("Inventário de Frutas:\n");
    for (int i = 0; i < total_frutas; i++) {
        printf("Código: %d, Nome: %s, Quantidade: %d, Preço: %.2f\n",
               inventario[i]->codigo, inventario[i]->nome, inventario[i]->quantidade, inventario[i]->preco);
    }
}

void buscar_fruta(Fruta* inventario[], int total_frutas) {
    int codigo;
    printf("Digite o código da fruta para buscar: ");
    scanf("%d", &codigo);
    for (int i = 0; i < total_frutas; i++) {
        if (inventario[i]->codigo == codigo) {
            printf("Fruta encontrada! Código: %d, Nome: %s, Quantidade: %d, Preço: %.2f\n",
                   inventario[i]->codigo, inventario[i]->nome, inventario[i]->quantidade, inventario[i]->preco);
            return;
        }
    }
    printf("Fruta não encontrada.\n");
}

void alterar_fruta(Fruta* inventario[], int total_frutas) {
    int codigo;
    printf("Digite o código da fruta para alterar: ");
    scanf("%d", &codigo);
    for (int i = 0; i < total_frutas; i++) {
        if (inventario[i]->codigo == codigo) {
            printf("Digite os novos dados da fruta:\n");
            printf("Nome: ");
            scanf(" %[^\n]", inventario[i]->nome);
            printf("Quantidade: ");
            scanf("%d", &inventario[i]->quantidade);
            printf("Preço: ");
            scanf("%f", &inventario[i]->preco);
            printf("Dados da fruta alterados com sucesso!\n");
            return;
        }
    }
    printf("Fruta não encontrada.\n");
}

void excluir_fruta(Fruta* inventario[], int* total_frutas) {
    int codigo;
    printf("Digite o código da fruta para excluir: ");
    scanf("%d", &codigo);
    for (int i = 0; i < *total_frutas; i++) {
        if (inventario[i]->codigo == codigo) {
            if (inventario[i]->quantidade > 0) {
                printf("Não é possível excluir uma fruta com estoque.\n");
                return;
            }
            free(inventario[i]);
            for (int j = i; j < *total_frutas - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            (*total_frutas)--;
            printf("Fruta excluída com sucesso!\n");
            return;
        }
    }
    printf("Fruta não encontrada.\n");
}

void vender_fruta(Fruta* inventario[], int total_frutas) {
    int codigo, quantidade;
    printf("Digite o código da fruta para venda: ");
    scanf("%d", &codigo);
    printf("Quantidade a vender: ");
    scanf("%d", &quantidade);
    for (int i = 0; i < total_frutas; i++) {
        if (inventario[i]->codigo == codigo) {
            if (inventario[i]->quantidade >= quantidade) {
                inventario[i]->quantidade -= quantidade;

                registrar_venda(inventario[i], quantidade);

                printf("Venda realizada com sucesso! Total: R$ %.2f\n", quantidade * inventario[i]->preco);
            } else {
                printf("Estoque insuficiente para realizar a venda.\n");
            }
            return;
        }
    }
    printf("Fruta não encontrada.\n");
}
