#include"aluno.h"
#include<stdlib.h>

#ifndef BUSCAMAT_H
#define BUSCAMAT_H

void trocaMat (Aluno* a, Aluno *b){
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

int particaoMat(Aluno *v, int ini, int fim){
    int i = ini, j = fim;
    Aluno pivo = v[(ini+fim)/2];
    while (1) {
        while(v[i].matricula < pivo.matricula){ 
            i++;
        } 
        while(v[j].matricula > pivo.matricula){  
            j--;
            } 
        if(i<j){
            trocaMat(&v[i], &v[j]); 
            i++;
            j--;
        }else
            return j; 
    }    
}

void QuickSortMat(Aluno *v, int ini, int fim){
    if(ini < fim ){
        int q = particaoMat(v, ini, fim);
        QuickSortMat(v, ini, q);
        QuickSortMat(v, q+1, fim);
    }
}

int rec_buscaBinariaMat(Aluno *v, int ini, int fim, Aluno *elem){
    if(ini > fim) return -1;
    int meio = (ini + fim)/2;
    if((*elem).matricula == v[meio].matricula) {
            strcpy ((*elem).nome, v[meio].nome);
            for (int i = 0; i < 3; i++) {
                (*elem).notas[i] = v[meio].notas[i];
            }
            return meio;
    } else{ 
        if((*elem).matricula < v[meio].matricula)
            return rec_buscaBinariaMat(v, ini, meio-1, elem); 
        else
            return rec_buscaBinariaMat(v, meio+1, fim, elem);
    }
}

int it_buscaBinariaMat(Aluno *v, int ini, int fim, Aluno *elem){
    int meio;
    while(ini <= fim){
        meio = (ini + fim)/2;
        if((*elem).matricula == v[meio].matricula) {
            strcpy ((*elem).nome, v[meio].nome);
            for (int i = 0; i < 3; i++) {
                (*elem).notas[i] = v[meio].notas[i];
            }
            return meio;
        } else{
            if((*elem).matricula < v[meio].matricula)
                fim = meio-1;
            else
                ini = meio+1;
        }
    }
    return -1;
}

#endif
