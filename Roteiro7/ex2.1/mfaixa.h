/*---------------- File: MFaixa.h  ------------------+
|Matriz de Faixa (malloc)                   |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 06/10/2023      |
+-------------------------------------------------------+ */

#ifndef MFAIXA_H
#define MFAIXA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Matriz de Faixa (Tridiagonal)
3 vetores:
Diagonal (A) -> tamanho N
Superior (B) -> tamanho N-1 (acima da diagonal principal)
Inferior (C) -> tamanho N-1 (abaixo da diagonal principal)
A B 0 0 0
C A B 0 0
0 C A B 0
0 0 C A B
0 0 0 C A
*/

/*
Indices:
[0,0]	[0,1]	    0	    0	    0	    0	    0	    0	    0	    0	
[1,0]	[1,1]	[1,2]	    0	    0	    0	    0	    0	    0	    0	
    0	[2,1]	[2,2]	[2,3]	    0	    0	    0	    0	    0	    0	
    0	    0	[3,2]	[3,3]	[3,4]	    0	    0	    0	    0	    0	
    0	    0	    0	[4,3]	[4,4]	[4,5]	    0	    0	    0	    0	
    0	    0	    0	    0	[5,4]	[5,5]	[5,6]	    0	    0	    0	
    0	    0	    0	    0	    0	[6,5]	[6,6]	[6,7]	    0	    0	
    0	    0	    0	    0	    0	    0	[7,6]	[7,7]	[7,8]	    0	
    0	    0	    0	    0	    0	    0	    0	[8,7]	[8,8]	[8,9]	
    0	    0	    0	    0	    0	    0	    0	    0	[9,8]	[9,9]
*/

typedef struct{
    int *diagonal;
    int *superior;
    int *inferior;
    int tam;
}MFaixa;

void zeraMatriz(MFaixa*);
MFaixa* criaMatriz(int);
void destroiMatriz(MFaixa*);
int preencheAleatorio(MFaixa*, int, int);
int insereElem(MFaixa*, int, int, int);
int consultaElem(MFaixa*, int, int);
void imprimeFaixaVetores(MFaixa*);
void imprimeFaixa(MFaixa*);

#endif