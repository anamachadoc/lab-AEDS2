#include"aluno.h"
#include<stdlib.h>

#ifndef BUSCANOME_H
#define BUSCANOME_H

void trocaNome (Aluno* a, Aluno *b){
	Aluno aux;
    strcpy (aux.nome, (*a).nome);
    aux.matricula = (*a).matricula;
    for (int i = 0; i < 3; i++) {
        aux.notas[i] = (*a).notas[i];
    }
    strcpy ((*a).nome, (*b).nome);
    (*a).matricula = (*b).matricula;
    for (int i = 0; i < 3; i++) {
        (*a).notas[i] = (*b).notas[i];
    }
	strcpy ((*b).nome, aux.nome);
    (*b).matricula = aux.matricula;
    for (int i = 0; i < 3; i++) {
        (*b).notas[i] = aux.notas[i];
    }
} 

int particaoNome(Aluno *v, int ini, int fim){
    int i = ini, j = fim;
    Aluno pivo = v[(ini+fim)/2];
    while (1) {
        while(strcmp (pivo.nome, v[i].nome) > 0){ 
            i++;
        } 
        while(strcmp (pivo.nome, v[j].nome) < 0){ 
            j--;
            } 
        if(i<j){
            trocaNome(&v[i], &v[j]); 
            i++;
            j--;
        }else
            return j; 
    }    
}

void QuickSortNome(Aluno *v, int ini, int fim){
    if(ini < fim ){
        int q = particaoNome(v, ini, fim);
        QuickSortNome(v, ini, q);
        QuickSortNome(v, q+1, fim);
    }
}

int rec_buscaBinariaNome(Aluno *v, int ini, int fim, Aluno *elem){
    if(ini > fim) return -1;
    int comparacao;
    int meio = (ini + fim)/2;
    comparacao = strcmp ((*elem).nome, v[meio].nome);
    if(comparacao == 0) {
            (*elem).matricula = v[meio].matricula;
            for (int i = 0; i < 3; i++) {
                (*elem).notas[i] = v[meio].notas[i];
            }
            return meio;
    } else{ 
        if(comparacao < 0)
            return rec_buscaBinariaNome(v, ini, meio-1, elem); 
        else
            return rec_buscaBinariaNome(v, meio+1, fim, elem);
    }
}

int it_buscaBinariaNome(Aluno *v, int ini, int fim, Aluno *elem){
    int meio, comparacao;
    while(ini <= fim){
        meio = (ini + fim)/2;
        comparacao = strcmp ((*elem).nome, v[meio].nome);
        if(comparacao == 0) {
            (*elem).matricula = v[meio].matricula;
            for (int i = 0; i < 3; i++) {
                (*elem).notas[i] = v[meio].notas[i];
            }
            return meio;
        } else{
            if(comparacao < 0)
                fim = meio-1;
            else
                ini = meio+1;
        }
    }
    return -1;
}

#endif
