/*---------------- File: buscaSequencial.c  ------------+
|Busca Sequencial                                       |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 22/11/2023      |
+-------------------------------------------------------+ */

#include<stdio.h>

#ifndef SEQUENCIAL_H
#define SEQUENCIAL_H

int buscaSequencial(int *v, int n, int elem, int *comp){
    int i;
    for(i=0; i<n; i++){
        (*comp)++;
        if(v[i] == elem) 
            return i; //Elemento encontrado
    }
    return -1; //Elemento encontrado
}

#endif
