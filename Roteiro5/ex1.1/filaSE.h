/*----------------- File: LSE.h  ----------------------+
|Fila Sequencial Estatica                               |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 19/09/2023      |
| Modificado por Ana Cláudia Machado em 02/10/2023
+-------------------------------------------------------+ */

#ifndef FILASE_H
#define FILASE_H
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct{
    int qtd, ini, fim;
    int dados[MAX];
}Fila;

Fila* criaFila();
void destroiFila(Fila*);
int tamanhoFila(Fila*);
int estaCheia(Fila*);
int estaVazia(Fila*);
int enfileirar(Fila*, int);
int desenfileirar(Fila*);
int verInicio(Fila*, int*);
void imprime(Fila*);

#endif