/*----------------- File: LDE.h  -----------------------+
|Lista Duplamente Encadeada                             |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 19/09/2023      |
| Modificado por Ana Cláudia Machado em 27/09/2023      |
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
void liberarNO(NO* q);
int insereIni(Lista* li, int elem);
int insereFim(Lista* li, int elem);
int removeIni(Lista *li);
int removeFim(Lista *li);
void imprimeLista(Lista* li);
void destroiLista(Lista* li);


#endif