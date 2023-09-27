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


#endif
