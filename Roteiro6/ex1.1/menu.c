#include"menu.h"

int existeDeque (Deque* dq) {
    if (dq != NULL) {
        return 1;
    }
    return 0;
}

void semDeque () {
    printf (" - Ainda nao existe uma deque alocado! Favor criar uma deque antes de escolher as demais opcoes!\n");
}

void mensagemResultado (int sucesso) {
    if (sucesso == 1) {
        printf (" - Operacao realizada com sucesso!\n");
    } else {
        printf (" - Nao foi possivel realizar a operacao solicitada!\n");
    }
}

void insercao (Deque* dq, int localInsere) {
    if (existeDeque(dq)) {
        if (!estaCheio(dq)) {
            int elem;
            printf (" - Digite o item a ser inserido: ");
            scanf ("%d", &elem);
            if (localInsere == 1) {
                mensagemResultado (insereIni (dq, elem));
            } else {
                mensagemResultado (insereFim (dq, elem));
            }
        } else {
            printf (" - Nao ha espaco, o deque ja esta cheio!\n");
        }
    } else {
        semDeque();
    }
}

void remocao (Deque* dq, int localRemove) {
    if (existeDeque(dq)) {
        if (!estaVazio(dq)) {
            if (localRemove == 1) {
                mensagemResultado (removeIni (dq));
            } else {
                mensagemResultado (removeFim (dq));
            }
        } else {
            printf (" - Nao ha nenhum item no deque!\n");
        }
    } else {
        semDeque();
    }
}

