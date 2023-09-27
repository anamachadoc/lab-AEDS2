/*----------------- File: LCSE.h  ----------------------+
|Lista Circular Simplesmente Encadeada                  |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 19/09/2023      |
| Modificado por Ana Cláudia Machado em 27/09/2023      |
+-------------------------------------------------------+ */

#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* prox;    
}NO;

typedef struct NO* Lista;

Lista* criaLista();
int listaVazia(Lista*);
NO* alocarNO();
void liberarNO(NO*);
int insereIni(Lista*, int);
int insereFim(Lista*, int);
int removeIni(Lista*);
int removeFim(Lista*);
void imprimeLista(Lista*);
void destroiLista(Lista*);
int tamanho (Lista*);
int procura (Lista*, int);
int verifica (int);

#endif