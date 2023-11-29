#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void troca(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
} 

void zerarCompMov (int *comp, int *mov) {
    *comp = 0;
    *mov = 0;
}

void SelectionSort(int *v, int n, int *comp, int *mov){
  int i, j, menor;
  for(i=0; i < n-1; i++){
    menor = i;
    for(j=i+1; j < n; j++){
       *comp += 1;
       if (v[j] < v[menor]) 
         menor = j;
    }
    if(i != menor){
      troca(&v[i], &v[menor]);
      *mov += 1;
    }
  }
}

void BubbleSort(int *v, int n, int *comp, int *mov){
    int i, j;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++){
			 *comp += 1;
             if (v[j]>v[j+1]) {
                 troca(&v[j], &v[j+1]);
				 *mov += 1;
             }
        }
}

void BubbleSort2(int *v, int n, int *comp, int *mov){
    int j, continua, fim = n;
    do{
        continua = 0;
        for(j=0; j < fim-1; j++){
			 *comp += 1;
             if (v[j]>v[j+1]) {
                 troca(&v[j], &v[j+1]);
				 *mov += 1;
                 continua = j;
             }
        }
        fim--;
    }while(continua != 0);
}

void InsertionSort(int *v, int n, int *comp, int *mov){
  int i, j, atual;
  for(i=1; i < n; i++){
    atual = v[i];
    *comp += 1;
    for(j=i; (j>0) && (atual < v[j-1]); j--){
       v[j] = v[j-1];
       *comp += 1;
       *mov += 1;
    }
    v[j] = atual;
  }
}