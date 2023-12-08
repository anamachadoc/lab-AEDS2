/*---------------- File: buscaBinaria.c  ---------------+
|Busca Binaria                                          |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 23/11/2023      |
+-------------------------------------------------------+ */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void troca(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
} 

int particao(int *v, int ini, int fim){
    int i = ini, j = fim;
    int pivo = v[(ini+fim)/2];
    while (1) {
        while(v[i] > pivo){ i++;} 
        
        while(v[j] < pivo){ j--;} 
        
        if(i<j){
            troca(&v[i], &v[j]); 
            i++;
            j--;
        }else
            return j; 
    }    
}

void QuickSort(int *v, int ini, int fim){
    if(ini < fim ){
        int q = particao(v, ini, fim);
        QuickSort(v, ini, q);
        QuickSort(v, q+1, fim);
    }
}

int rec_buscaBinaria(int *v, int ini, int fim, int elem, int *comp){
    if(ini > fim) return -1;
    int meio = (ini + fim)/2;
    (*comp)++;
    if(v[meio] == elem) 
        return meio;
    else 
        if(elem > v[meio])
            return rec_buscaBinaria(v, ini, meio-1, elem, comp);
        else
            return rec_buscaBinaria(v, meio+1, fim, elem, comp);
}

int it_buscaBinaria(int *v, int ini, int fim, int elem, int *comp){
    int meio;
    while(ini <= fim){
        meio = (ini + fim)/2;
        (*comp)++;
        if(elem == v[meio]) return meio;
        else
            if(elem > v[meio])
                fim = meio-1;
            else
                ini = meio+1;
    }
    return -1;
}

int* copiaVetor(int* v, int n){
    int i;
    int *v2;
    v2 = (int*) malloc (n*sizeof(int));
    for(i=0; i<n; i++) v2[i] = v[i];
    return v2;
}
void imprimeVetor(int* v, int n){
    int i, prim = 1;
    printf("[");
    for(i=0; i<n; i++)
        if(prim){ printf("%d", v[i]); prim = 0; }
        else printf(", %d", v[i]);
    printf("]\n");
}

void preencheAleatorio(int* v, int n, int ini, int fim){
    int i;
    for(i=0; i<n; i++)
        v[i] = ini + rand() % (fim-ini + 1); 
}

void resultado (int ind) {
    if(ind != -1)
        printf("O elemento foi encontrado na pos %d.\n", ind);
    else
        printf("O elemento NAO foi encontrado!\n");
}
