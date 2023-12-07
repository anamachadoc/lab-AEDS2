/*---------------- File: buscaSequencial.c  ------------+
|Busca Sequencial                                       |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 22/11/2023      |
+-------------------------------------------------------+ */

#include"vetor.h"
#include <stdio.h>
#include <stdlib.h>

//Medidas de Complexidade
int comp; //Num. de comparacoes

int buscaSequencial(int *v, int n, int elem){
    int i;
    for(i=0; i<n; i++){
        comp++;
        if(v[i] == elem) 
            return i; //Elemento encontrado
    }
    return -1; //Elemento encontrado
}

