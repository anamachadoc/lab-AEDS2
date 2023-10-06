/*----------------- pile: Pilha.h  ----------------------+
|Pilha Sequencial Estatica                              |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 20/09/2023      |
| Modificado por Ana Cláudia Machado em 05/10/2023      |
+-------------------------------------------------------+ */
#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct{
    int topo;
    int dados[MAX];
}Pilha;

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