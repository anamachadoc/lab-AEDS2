#include"menu.h"

int existeAVL (AVL* AVL) {
    if (AVL != NULL) {
        return 1;
    }
    return 0;
}

void semAVL () {
    printf ("\nAinda nao existe uma AVL alocada! Favor criar uma AVL antes de escolher as demais opcoes!");
}

void mensagemResultado (int sucesso) {
    if (sucesso == 1) {
        printf ("\nOperacao realizada com sucesso!");
    } else {
        printf ("\nNao foi possivel realizar a operacao solicitada!");
    }
}

