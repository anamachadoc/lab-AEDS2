#ifndef PSE_H
#define PSE_H
#include<stdio.h>
#include<stdlib.h>

typedef struct NO{
    int info ;
    struct NO* prox ;
}NO;

typedef struct {
    int qtd;
    struct NO* topo ;
} Pilha ;

Pilha* criaPilha();
void destroiPilha(Pilha*);
int tamanhoPilha(Pilha*);
int estaCheia(Pilha*);
int estaVazia(Pilha*);
int empilhar(Pilha*, int);
int desempilhar(Pilha*);
int verTopo(Pilha*, int*);
void imprime(Pilha*);

#endif