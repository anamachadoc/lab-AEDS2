/*---------------- File: MEsparsaCSR.h  ----------------+
|Matriz Esparsa (malloc)                                |
|Compressed Sparse Row - CSR	                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 09/10/2023      |
+-------------------------------------------------------+ */

#ifndef MESPARSACSR_H
#define MESPARSACSR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MSD.h"

/*
Matriz Esparsa (Compressed Sparce Row - CSR)
3 vetores:
A -> tamanho QNN (Quantidade de nao nulos)
IA -> tamanho N+1 (QNN por linha)
    IA[0] = 0;
    IA[i] = IA[i-1] + QNN da linha (i-1)
JA -> tamanho QNN (indices de coluna de cada elemento em A)

Input : 10  20  0  0  0  0
         0  30  0  4  0  0
         0   0 50 60 70  0
         0   0  0  0  0 80

Output :  A = [10 20 30 4 50 60 70 80],
         IA = [0 2 4 7 8]
         JA = [0  1 1 3 2 3 4 5]
*/

typedef struct{
    int *A; //Valores
    int *IA;
    int *JA;
    int lin, col, QNN, QI;
}MEsparsaCSR;
//QNN - Quantidade de Nao Nulos
//QI - Quantidade de Inseridos

MEsparsaCSR* criaMatrizEsparsa(int, int,int);
int* meuRealloc(int*, int);
void imprimeEsparsaVetores(MEsparsaCSR*);
int insereElemEsparsa(MEsparsaCSR*, int, int, int);
int removeElemEsparsa(MEsparsaCSR*, int, int);
MEsparsaCSR* transformarEmCSR(Matriz*);
int consultaElemEsparsa(MEsparsaCSR*, int, int);
void imprimeEsparsa(MEsparsaCSR*);
void destroiMatrizEsparsa(MEsparsaCSR*);

#endif