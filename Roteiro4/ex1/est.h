/*----------------- File: Est.h ----------------------+
|Lista Sequencial Estatica                              |
|                                                       |
|                                                       |
| Implementado por Guilherme C. Pena em 12/09/2023      |
| Modificado por Ana Cláudia Machado em 27/09/2023    |
+-------------------------------------------------------+ */

#ifndef EST_H
#define EST_H
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    int qtd;
    int dados[MAX];
}Lista;

Lista* criaLista();
void destroiLista(Lista*);
int tamanhoLista(Lista*);
int listaCheia(Lista*);
int listaVazia(Lista*);
int insereFim(Lista*, int);
int insereIni(Lista*, int);
int imprimeLista(Lista*);
int removeFim(Lista*);
int removeIni(Lista*);
int procura (Lista*, int);
int verifica (int);
int insereOrdenada (Lista*, int);
int remocao (Lista*, int);
int confereRemocao (int);

#endif
