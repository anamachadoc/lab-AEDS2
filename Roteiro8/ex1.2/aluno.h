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
#include <string.h>

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
int insereRec(NO**, Aluno);
int insereElem(ABP*, Aluno);
int pesquisaRec(NO**, Aluno*);
int pesquisa(ABP*, Aluno*);
NO* removeAtual(NO*);
int removeIte(NO**, Aluno);
int removeElem(ABP*, Aluno);
void em_ordem(NO*, int);
void limpar (void);
void imprimeAluno (Aluno);
Aluno infoAluno();
void reiniciarAluno (Aluno*);
void maiorNota (NO*, Aluno*);
void menorNota (NO*, Aluno*);


#endif

