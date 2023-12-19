/*---------------- File: Hash.c  -----------------------+
|Tabela Hash (Dinâmica)                                 |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 24/11/2023      |
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

int chaveDivisao(int chave, int tam){
    return (chave & 0x7FFFFFFF) % tam;
}

int chaveMultiplicacao(int chave, int tam){
    float A = 0.6180339887; //constante: 0 < A < 1
    float val = chave * A;
    val = val - (int) val;
    return (int) (tam * val);
}

int chaveDobra(int chave, int tam){
    int pos, n_bits = 30;
    
    int p = 1;
    int r = p << n_bits;
    while((chave & r) != r){ n_bits--; r = p << n_bits; }

    n_bits++;
    pos = chave;
    while(pos > tam){
        int metade_bits = n_bits/2;
        int parte1 = pos >> metade_bits;
        parte1 = parte1 << metade_bits;
        int parte2 = pos ^ parte1;
        parte1 = pos >> metade_bits;
        pos = parte1 ^ parte2;
        n_bits = n_bits/2;
    }
    return pos;
}

int escolheFuncao(int funcao, int elem, Hash *h) {
    int pos;
    switch (funcao) {
        case 1:
            pos = chaveDivisao(elem, h->tam);
            break;
        case 2:
            pos = chaveDobra(elem, h->tam);
            break;
        case 3:
            pos = chaveMultiplicacao(elem, h->tam);
            break;
        default:
            exit(1);
    }
    return pos;
}

int insereHash_semTratar(Hash* h, int elem, int funcao){
    if(h == NULL) return 0;
    int pos = escolheFuncao (funcao, elem, h);
    if(h->tabela[pos] == NULL){
        int* novo = (int*) malloc (sizeof(int));
        if(novo == NULL) return 0;
        *novo = elem;
        h->tabela[pos] = novo;
        h->qtd++;
    }else *(h->tabela[pos]) = elem;
    return 1;
}

int buscaHash_semTratar(Hash* h, int elem, int *p, int funcao){
    if(h == NULL) return 0;
    int pos = escolheFuncao(funcao, elem, h);
    if(h->tabela[pos] == NULL) return 0;
    if(*(h->tabela[pos]) == elem){
        *p = pos;
        return 1;
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