#include <stdio.h>
#include "vendas.h"

void registrar_venda(Fruta* fruta, int quantidade) {
    FILE *vendas_file = fopen("vendas.txt", "a");
    if (vendas_file != NULL) {
        fprintf(vendas_file, "Venda: Código: %d, Nome: %s, Quantidade: %d, Total: R$ %.2f\n",
                fruta->codigo, fruta->nome, quantidade, quantidade * fruta->preco);
        fclose(vendas_file);
    } else {
        printf("Erro ao abrir o arquivo de vendas.\n");
    }
}

void listar_vendas() {
    FILE *vendas_file = fopen("vendas.txt", "r");
    if (vendas_file == NULL) {
        printf("Erro ao abrir o arquivo de vendas.\n");
        return;
    }

    char linha[256];
    printf("Lista de Vendas:\n");
    while (fgets(linha, sizeof(linha), vendas_file) != NULL) {
        printf("%s", linha);
    }
    fclose(vendas_file);
}
