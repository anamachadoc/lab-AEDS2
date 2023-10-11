/*----------------- File: FPSE.h  ----------------------+
|Fila de Prioridades Simplesmente Encadeada             |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 26/09/2023      |
+-------------------------------------------------------+ */

#ifndef FPSE_H
#define FPSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info, prio;
    struct NO* prox;
}NO;

typedef struct NO* FilaP;

NO* alocarNO();
void liberarNO(NO*);
FilaP* criaFila();
int estaVazia(FilaP*);
int inserirPrio(FilaP*, int, int);
int removeIni(FilaP*);
int verIni(FilaP*, int*);
void imprime(FilaP*);
void destroiFila(FilaP*);

#endif
