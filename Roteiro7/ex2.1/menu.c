#include"menu.h"

int existeMFaixa (MFaixa* MF) {
    if (MF != NULL) {
        return 1;
    }
    return 0;
}

void semMFaixa () {
    printf ("\nAinda nao existe uma matriz de faixa alocada! Favor criar uma matriz de faixa antes de escolher as demais opcoes!");
}

void mensagemResultado (int sucesso) {
    if (sucesso == 1) {
        printf ("\nOperacao realizada com sucesso!");
    } else {
        printf ("\nNao foi possivel realizar a operacao solicitada!");
    }
}

