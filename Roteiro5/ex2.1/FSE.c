#include<stdio.h>
#include<stdlib.h>
#include"FSE.h"

Fila* criaFila () {
    Fila* fi = (Fila*)malloc(sizeof(Fila));
    if (fi != NULL) {
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

int filaVazia (Fila* fi) {
    if (fi == NULL) return -1; // nao existe fila
    if (fi->inicio == NULL) return 1; // fila vazia
    return 0; // ha elementos
}

int insere (Fila* fi, int info) {
    if (fi == NULL) return 0;
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) return 0;
    novo->info = info;
    novo->prox = NULL;
    if (fi->final == NULL) {
        fi->inicio = novo;
    } else {
        fi->final->prox = novo;
    }
    fi->final = novo;
    fi->qtd++;
    return 1;
}

int remove (Fila* fi) {
    if (fi == NULL) return 0;
    if (fi->inicio == NULL) return 0;
    NO* aux = fi->inicio;
    fi->inicio = fi->inicio->prox;
    free(aux);
    if (fi->inicio == NULL) {
        fi->final = NULL;
    }
    fi->qtd--;
    return 1;
}

int tamanho (Fila* fi) {
    if (fi == NULL) return 0;
    return fi->qtd;
}

int consultaElem (Fila* fi, int* elem) {
    if (fi == NULL) return 0;
    if (fi->inicio == NULL) return 0;
    *elem = fi->inicio->info;
    return 1;
}

void destroiFila (Fila* fi) {
    if (fi != NULL) {
        NO* aux;
        while (fi->inicio != NULL) {
            aux = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(aux);
        }
        free(fi);
    }
}