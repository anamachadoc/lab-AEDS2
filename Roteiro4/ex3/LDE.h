/*----------------- File: LDE.h  -----------------------+
|Lista Duplamente Encadeada                             |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 19/09/2023      |
| Modificado por Ana Cláudia Machado em 28/09/2023      |
+-------------------------------------------------------+ */

#ifndef LDE_H
#define LDE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* prox;
    struct NO* ant;
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
void verifica (int);
int procura (Lista*, int);
int insereOrdenada (Lista*, int);
int removeElem (Lista*, int);
void remocao (int);

#endif