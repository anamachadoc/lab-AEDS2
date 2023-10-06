#include"PSE.h"

Pilha* criaPilha() {
    Pilha *pi = (Pilha*)malloc(sizeof(Pilha));
    if (pi != NULL) {
        pi == NULL;
    }
    return pi;
}
void destroiPilha(Pilha* pi) {
    if (pi != NULL) {
        NO* aux;
        while (pi->topo != NULL) {
            aux = pi->topo;
            pi->topo = pi->topo->prox;
            free(aux);
        }
        free(pi->topo);
    }
}
int tamanhoPilha(Pilha* pi) {
    if (pi == NULL) return 0;
    int tam = 0;
    NO* aux = pi->topo;
    while (aux != NULL) {
        tam++;
        aux = aux->prox;
    }
    return tam;
}

int estaCheia(Pilha* pi) {
    return 0;
}

int estaVazia(Pilha* pi) {
    if (pi == NULL) return 1;
    if (pi->topo == NULL) return 1;
    return 0;
}

int empilhar(Pilha* pi, int info) {
    if (pi == NULL) return 0;
    NO* novo = (NO*)malloc(sizeof(NO));
    if(novo == NULL) return 0;
    novo->info = info;
    novo->prox = pi->topo;
    pi->topo = novo;
    return 1;
}

int desempilhar(Pilha* pi) {
    if (pi == NULL) return 0;
    if (pi->topo == NULL) return 0;
    NO* aux = pi->topo;
    pi->topo = aux->prox;
    free(aux);
    return 1;
}

int verTopo(Pilha* pi, int* topo) {
    if (pi == NULL) return 0;
    if (pi->topo == NULL) return 0;
    *topo = pi->topo->info;
    return 1;
}

void imprime(Pilha* pi) {
  if(pi == NULL) return;
  if(estaVazia(pi)){
    printf("Pilha Vazia!\n");
    return;
  }
  NO* aux;
  aux = pi->topo;
  printf("Elementos: \n");
  do{
    printf("%d ", aux->info);
    aux = aux->prox;
  }while(aux != NULL);
  printf("\n");
}
