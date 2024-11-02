#ifndef FRUTA_H
#define FRUTA_H

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Fruta;

void cadastrar_fruta(Fruta* inventario[], int* total_frutas);
void listar_frutas(Fruta* inventario[], int total_frutas);
void buscar_fruta(Fruta* inventario[], int total_frutas);
void alterar_fruta(Fruta* inventario[], int total_frutas);
void excluir_fruta(Fruta* inventario[], int* total_frutas);
void vender_fruta(Fruta* inventario[], int total_frutas);

#endif // FRUTA_H
