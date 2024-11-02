#include <stdio.h>
#include <stdlib.h>
#include "fruta.h"
#include "vendas.h"  

#define MAX_FRUTAS 100

int main() {
    Fruta* inventario[MAX_FRUTAS];
    int total_frutas = 0;
    int opcao;
    
    do {
        printf("\nMenu do Mercado de Frutas:\n");
        printf("1. Cadastrar fruta\n");
        printf("2. Listar frutas\n");
        printf("3. Buscar fruta\n");
        printf("4. Alterar fruta\n");
        printf("5. Excluir fruta\n");
        printf("6. Vender fruta\n");
        printf("7. Listar vendas\n"); 
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrar_fruta(inventario, &total_frutas);
                break;
            case 2:
                listar_frutas(inventario, total_frutas);
                break;
            case 3:
                buscar_fruta(inventario, total_frutas);
                break;
            case 4:
                alterar_fruta(inventario, total_frutas);
                break;
            case 5:
                excluir_fruta(inventario, &total_frutas);
                break;
            case 6:
                vender_fruta(inventario, total_frutas);
                break;
            case 7:
                listar_vendas(); 
                break;
            case 8:
                printf("Saindo do programa...\n");
                for (int i = 0; i < total_frutas; i++) {
                    free(inventario[i]);
                }
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 8);

    return 0;
}
