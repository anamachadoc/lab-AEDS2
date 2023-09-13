#include<stdio.h>
#include"ex12.h"

int main () {
    catalogoProdutos* catalogo = (catalogoProdutos*)malloc(sizeof(catalogoProdutos));
    catalogo.quantProdutos = -1;
    menuUsuario (catalogo);
    return 0;
}
