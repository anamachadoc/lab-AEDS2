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

//////////////////////////////////////////////////////////////////////////

void ShellSort(int *v, int n, int *comp, int *mov) {
  int i, j, atual;
  int h = 1;
  while(h < n) h = 3*h+1;
  while (h > 0) {
    for(i = h; i < n; i++) {
      atual = v[i];
      j = i;
      *comp += 1;
      while (j > h-1 && atual >= v[j - h]) {
        *mov += 1;
        v[j] = v[j - h];
        j = j - h;
      }
      v[j] = atual;
    }
    h = h/3;
  }
}

//////////////////////////////////////////////////////////////////////////


int particao(int *v, int ini, int fim, int *comp, int *mov){
    int i = ini, j = fim;
    int pivo = v[(ini+fim)/2];
    while (1) {
        while(v[i] > pivo){ i++; *comp += 1; } //procura algum >= pivo do lado esquerdo
        
        while(v[j] < pivo){ j--; *comp += 1;} //procura algum <= pivo do lado direito
        
        if(i<j){
            *mov += 1;
            troca(&v[i], &v[j]); //troca os elementos encontrados
            i++;
            j--;
        }else
            return j; //retorna o local onde foi feita a particao
    }    
}

void QuickSort(int *v, int ini, int fim, int n, int *comp, int *mov){
    if(ini < fim ){
        int q = particao(v, ini, fim, comp, mov);
        //printf("Parts: (%d, %d) e (%d, %d): ", ini, q, q+1, fim);
        //imprimeVetor(v, n);
        QuickSort(v, ini, q, n, comp, mov);
        QuickSort(v, q+1, fim, n, comp, mov);
    }
}

////////////////////////////////////////////////////////////////////////////////////

void Merge(int *v, int ini, int meio, int fim, int *comp, int *mov){
    int tam = fim-ini+1;
    //Vetor Auxiliar - A
    int *A = (int*) malloc (tam*sizeof(int));
    int i = ini, j = meio+1, k = 0;
    while (i<=meio && j<=fim) {
        if (v[i] > v[j]){ A[k] = v[i]; i++; }
        else { A[k] = v[j]; j++; }
        *comp += 1;
        k++;
    }
    while (i<=meio) { A[k] = v[i];  i++;  k++; }
    while (j<=fim) { A[k] = v[j];  j++;  k++; }
    for(i = ini, k=0; i<=fim; i++, k++) {
        v[i] = A[k];
        *mov += 1;
    }
    free(A);
}

void MergeSort(int *v, int ini, int fim, int *comp, int *mov){
    if(ini < fim ){
        int meio = (ini + fim)/2;
        MergeSort(v, ini, meio, comp, mov);
        MergeSort(v, meio+1, fim, comp, mov);
        Merge(v, ini, meio, fim, comp, mov);
    }
}

////////////////////////////////////////////////////////////////////////////////////////

void criaHeap(int *v, int pai, int fim, int *comp){
    int aux = v[pai];
    int filho = 2*pai + 1;
    while(filho <= fim){
        *comp += 1;
        if(filho < fim)
            if(v[filho] > v[filho+1])
                filho++;
        if(aux > v[filho]){
            v[pai] = v[filho];
            pai = filho;
            filho = 2*pai + 1;
        }else filho = fim + 1;
    }
    v[pai] = aux;
}

void HeapSort(int *v, int n, int *comp, int *mov){
    int i;
    for(i=(n-1)/2; i>=0; i--)
        criaHeap(v, i, n-1, comp);
    for(i=n-1; i>=1; i--){
        troca(&v[0], &v[i]);
        *mov += 1;
        criaHeap(v, 0, i-1, comp);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////