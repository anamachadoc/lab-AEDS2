#include<stdio.h>
#include<stdlib.h>
#include"FSE.h"

Fila* criaFila () {
    Fila* fi = (Fila*)malloc(sizeof(Fila));
    if (fi != NULL) {
        fi->fim = NULL;
        fi->ini = NULL;
        fi->qtd = 0;
    }
    return fi;
}

int estaVazia (Fila* fi) {
    if (fi == NULL) return -1; // nao existe fila
    if (fi->ini == NULL) return 1; // fila vazia
    return 0; // ha elementos
}

int enfileirar (Fila* fi, int info) {
    if (fi == NULL) return 0;
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) return 0;
    novo->info = info;
    novo->prox = NULL;
    if (fi->fim == NULL) {
        fi->ini = novo;
    } else {
        fi->fim->prox = novo;
    }
    fi->fim = novo;
    fi->qtd++;
    return 1;
}

int desenfileirar (Fila* fi) {
    if (fi == NULL) return 0;
    if (fi->ini == NULL) return 0;
    NO* aux = fi->ini;
    fi->ini = fi->ini->prox;
    free(aux);
    if (fi->ini == NULL) {
        fi->fim = NULL;
    }
    fi->qtd--;
    return 1;
}

int tamanho (Fila* fi) {
    if (fi == NULL) return 0;
    return fi->qtd;
}

int verInicio (Fila* fi, int* elem) {
    if (fi == NULL) return 0;
    if (fi->ini == NULL) return 0;
    *elem = fi->ini->info;
    return 1;
}

void destroiFila (Fila* fi) {
    if (fi != NULL) {
        NO* aux;
        while (fi->ini != NULL) {
            aux = fi->ini;
            fi->ini = fi->ini->prox;
            free(aux);
        }
        free(fi);
    }
}

int estaCheia (Fila* fi) {
    return 0;
}

void imprime(Fila* fi){
  if(fi == NULL) return;
  if(estaVazia(fi)){
    printf("Fila Vazia!\n");
    return;
  }
  NO* aux;
  aux = fi->ini;
  printf("Elementos: \n");
  do{
    printf("%d ", aux->info);
    aux = aux->prox;
  }while(aux != NULL);
  printf("\n");
}