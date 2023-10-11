/*----------------- File: FPHeap.h ---------------------+
|Fila de Prioridades com Heap Binaria                   |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 26/09/2023      |
+-------------------------------------------------------+ */

#ifndef FPHEAP_H
#define FPHEAP_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct NO{
    int info, prio;
}NO;
typedef struct{
    int qtd;
    NO dados[MAX];
}FilaP;

FilaP* criaFila();
void destroiFila(FilaP*);
int tamanhoFila(FilaP*);
int estaCheia(FilaP*);
int estaVazia(FilaP*);
void trocaNO(NO*, NO*);
void ajustaHeapInsere(FilaP*, int);
int inserirPrio(FilaP*, int, int);
void ajustaHeapRemove(FilaP*, int);
int removeIni(FilaP*);
int verIni(FilaP*, int*, int*);
void imprime(FilaP*);

#endif
