#include"menu.h"

int existeFila (Fila* fi) {
    if (fi != NULL) {
        return 1;
    }
    return 0;
}

void semFila () {
    printf (" - Ainda nao existe uma fila alocada! Favor criar uma fila antes de escolher as demais opcoes!\n");
}

void mensagemResultado (int sucesso) {
    if (sucesso == 1) {
        printf (" - Operacao realizada com sucesso!\n");
    } else {
        printf (" - Nao foi possivel realizar a operacao solicitada!\n");
    }
}

