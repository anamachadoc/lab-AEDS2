#include"menu.h"

int existeMEsparsaCSR (MEsparsaCSR* CSR) {
    if (CSR != NULL) {
        return 1;
    }
    return 0;
}

void semMEsparsaCSR () {
    printf ("\nAinda nao existe uma matriz CSR alocada! Favor criar uma matriz CSR antes de escolher as demais opcoes!");
}

void mensagemResultado (int sucesso) {
    if (sucesso == 1) {
        printf ("\nOperacao realizada com sucesso!");
    } else {
        printf ("\nNao foi possivel realizar a operacao solicitada!");
    }
}

