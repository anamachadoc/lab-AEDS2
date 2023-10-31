/*---------------- File: ABP.h  ------------------------+
|Arvore Binaria de Pesquisa (ABP)                       |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 12/10/2023      |
| Modificado por Ana Cláudia Machado em 30/10/2023      |
+-------------------------------------------------------+ */

#ifndef ABP_H
#define ABP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    int matricula;
    double nota;
}Aluno;

typedef struct NO{
    Aluno info;
    struct NO* esq;
    struct NO* dir;
}NO;

typedef struct NO* ABP;

NO* alocarNO();
void liberarNO(NO*);
ABP* criaABP();
void destroiRec(NO*);
void destroiABP(ABP*);
int estaVazia(ABP*);
int insereRec(NO**, int);
int insereIte(NO**, int);
int insereElem(ABP*, int);
int pesquisaRec(NO**, int);
int pesquisaIte(NO**, int);
int pesquisa(ABP*, int);
int removeRec(NO**, int);
NO* removeAtual(NO*);
int removeIte(NO**, int);
int removeElem(ABP*, int);
void em_ordem(NO*, int);
void pre_ordem(NO*, int);
void pos_ordem(NO*, int);
void imprime(ABP*);
void numNos (NO*, int*);

#endif

