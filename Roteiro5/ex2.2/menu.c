#include"menu.h"

int existePilha (Pilha* fi) {
    if (fi != NULL) {
        return 1;
    }
    return 0;
}

void semPilha () {
    printf (" - Ainda nao existe uma pilha alocada! Favor criar uma pilha antes de escolher as demais opcoes!\n");
}

void mensagemResultado (int sucesso) {
    if (sucesso == 1) {
        printf (" - Operacao realizada com sucesso!\n");
    } else {
        printf (" - Nao foi possivel realizar a operacao solicitada!\n");
    }
}

