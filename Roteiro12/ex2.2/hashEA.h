/*---------------- File: Hash.c  -----------------------+
|Tabela Hash (Dinâmica)                                 |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 24/11/2023      |
| Modificado por Ana Cláudia Machado em 08/12/2023      |
+-------------------------------------------------------+ */

#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int **tabela;
    int tam, qtd;
}Hash;


Hash* criaHash(int t){
    Hash* h;
    h = (Hash*) malloc (sizeof(Hash));
    if(h != NULL){
        h->tam = t; h->qtd = 0;
        h->tabela = (int**) malloc (t*sizeof(int*));
        if(h->tabela == NULL) return NULL;
        int i;
        for(i = 0; i<t; i++)
            h->tabela[i] = NULL;
    }
    return h;
}


void destroiHash(Hash *h){
    if(h != NULL){
        int i;
        for(i = 0; i<h->tam; i++)
            if(h->tabela[i] != NULL)
                free(h->tabela[i]);
        free(h->tabela);
        free(h);
    }
}

int chaveMultiplicacao(int chave, int tam){
    float A = 0.6180339887; //constante: 0 < A < 1
    float val = chave * A;
    val = val - (int) val;
    return (int) (tam * val);
}

int sondagemLinear(int pos, int i, int tam){
    return ( (pos + i) & 0x7FFFFFFF) % tam;
}

int sondagemQuadratica(int pos, int i, int tam){
    pos = pos + 2*i + 5*i*i;
    return ( pos & 0x7FFFFFFF) % tam;
}

int sondagemDuploHash(int H1, int chave, int i, int tam){
    int H2 = chaveMultiplicacao(chave, tam-1) + 1;
    return ( (H1 + i*H2) & 0x7FFFFFFF) % tam;
}

int escolheSondagem(int funcao, int elem, Hash *h, int pos, int i) {
    int newPos;
    switch (funcao) {
        case 1:
            newPos = sondagemLinear(pos, i, h->tam);
            break;
        case 2:
            newPos = sondagemQuadratica(pos, i, h->tam);
            break;
        case 3:
            newPos = sondagemDuploHash(pos, elem, i, h->tam);
            break;
        default:
            exit(1);
    }
    return newPos;
}

int insereHash_EnderAberto(Hash* h, int elem, int funcao){
  if(h == NULL) return 0;
  int i, pos, newPos;
  pos = chaveMultiplicacao(elem, h->tam);
  if (h->tabela[pos] != NULL) {
    for(i=0; i<h->tam; i++){
        newPos = escolheSondagem(funcao, elem, h, pos, i);
        if(h->tabela[newPos] == NULL){
            int* novo = (int*) malloc (sizeof(int));
            if(novo == NULL) return 0;
            *novo = elem;
            h->tabela[newPos] = novo;
            h->qtd++;
            return 1;
        }
    }
  } else {
    int* novo = (int*) malloc (sizeof(int));
    if(novo == NULL) return 0;
    *novo = elem;
    h->tabela[pos] = novo;
    h->qtd++;
    return 1;
  }
  return 0;
}

int buscaHash_EnderAberto(Hash* h, int elem, int *p, int funcao){
    if(h == NULL) return 0;
    int i, pos, newPos;
    pos = chaveMultiplicacao(elem, h->tam);
    if (h->tabela[pos] != NULL && *(h->tabela[pos]) == elem) {
        *p = pos;
        return 1;
    } else {
        for(i=0; i<h->tam; i++){
            newPos = escolheSondagem(funcao, elem, h, pos, i);
            if(h->tabela[newPos] == NULL) return 0;
            if(*(h->tabela[newPos]) == elem){
                *p = newPos;
                return 1;
            }
        }
    }
    return 0;
}

void imprimeHash(Hash *h){
    if(h == NULL) return;
    int i;
    for(i=0; i<h->tam; i++){
        printf("%d: ", i);
        if(h->tabela[i] == NULL) printf("NULL\n");
        else printf("%d\n", *(h->tabela[i]));
    }
}

#endif