/*----------------- File: Deque.h  ---------------------+
|Deque Sequencial Estatico                              |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 21/09/2023      |
+-------------------------------------------------------+ */

#ifndef DSE_H
#define DSE_H
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct{
    int qtd, ini, fim;
    int dados[MAX];
} Deque;

Deque* criaDeque();
void destroiDeque(Deque*);
int tamanhoDeque(Deque*);
int estaCheio(Deque*);
int estaVazio(Deque*);
int insereIni(Deque*, int);
int insereFim(Deque*, int);
int removeIni(Deque*);
int removeFim(Deque*);
int verInicio(Deque*, int*);
int verFim(Deque*, int*);
void imprime(Deque*);

#endif