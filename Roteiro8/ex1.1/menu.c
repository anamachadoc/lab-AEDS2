#include"menu.h"

int existeABP (ABP* ABP) {
    if (ABP != NULL) {
        return 1;
    }
    return 0;
}

void semABP () {
    printf ("\nAinda nao existe uma ABP alocada! Favor criar uma ABP antes de escolher as demais opcoes!");
}

void mensagemResultado (int sucesso) {
    if (sucesso == 1) {
        printf ("\nOperacao realizada com sucesso!");
    } else {
        printf ("\nNao foi possivel realizar a operacao solicitada!");
    }
}

