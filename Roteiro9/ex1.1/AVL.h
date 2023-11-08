/*---------------- File: AVL.h  ------------------------+
|Arvore AVL                                             |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 23/10/2023      |
+-------------------------------------------------------+ */

#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#define MAIOR(a, b) ((a > b) ? (a) : (b))

typedef struct NO{
    int info, fb, alt;
    struct NO* esq;
    struct NO* dir;
}NO;

typedef struct NO* AVL;

NO* alocarNO();
void liberarNO(NO*);
AVL* criaAVL();
void destroiRec(NO*);
void destroiAVL(AVL*);
int estaVazia(AVL*);
int altura(NO*);
int FB(NO*);
void avl_RotDir(NO**);
void avl_RotEsq(NO**);
void avl_RotEsqDir(NO**);
void avl_RotDirEsq(NO**);
void avl_RotEsqDir2(NO**);
void avl_RotDirEsq2(NO**);
void avl_AuxFE(NO**);
void avl_AuxFD(NO**);
int insereRec(NO**, int);
int insereElem(AVL*, int);
int pesquisaRec(NO**, int);
int pesquisa(AVL*, int);
int removeRec(NO**, int);
int removeElem(AVL*, int);
void em_ordem(NO*, int);
void pre_ordem(NO*, int);
void pos_ordem(NO*, int);
void imprime(AVL*);
void numNos (NO*, int*);
void zerarNos (int*);

#endif