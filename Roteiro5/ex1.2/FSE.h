#ifndef FSE_H
#define FSE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* prox ;
} NO;

typedef struct {
    int qtd;
    struct NO* ini;
    struct NO* fim;
} Fila ;

Fila* criaFila ();
int estaVazia (Fila*);
int enfileirar (Fila*, int);
int desenfileirar (Fila*);
int tamanho (Fila*);
int verInicio (Fila*, int*);
void destroiFila (Fila*);
void imprime (Fila*);
int estaCheia (Fila*);

#endif
