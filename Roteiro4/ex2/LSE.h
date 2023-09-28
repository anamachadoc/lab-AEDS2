/*----------------- File: LSE.h  ----------------------+
|Lista Simplesmente Encadeada                           |
|                                                       |
|                                                       |
| Implementado por Guilherme C. Pena em 14/09/2023      |
| Modificado por Ana Cláudia Machado em 27/09/2023      |
+-------------------------------------------------------+ */

#ifndef LISTASE_H
#define LISTASE_H
#include<stdio.h>
#include<stdlib.h>

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
int procura (Lista*, int);
void verifica (int);
int tamanho (Lista*);
int insereOrdenada (Lista*, int);

#endif
