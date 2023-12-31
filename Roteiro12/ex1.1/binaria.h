/*---------------- File: buscaBinaria.c  ---------------+
|Busca Binaria                                          |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 23/11/2023      |
+-------------------------------------------------------+ */
#ifndef BINARIA_H
#define BINARIA_H

void troca(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
} 

int particao(int *v, int ini, int fim){
    int i = ini, j = fim;
    int pivo = v[(ini+fim)/2];
    while (1) {
        while(v[i] < pivo){ i++; } //procura algum >= pivo do lado esquerdo
        while(v[j] > pivo){ j--; } //procura algum <= pivo do lado direito
        
        if(i<j){
            troca(&v[i], &v[j]); //troca os elementos encontrados
            i++;
            j--;
        }else
            return j; //retorna o local onde foi feita a particao
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
        if(elem < v[meio])
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
            if(elem < v[meio])
                fim = meio-1;
            else
                ini = meio+1;
    }
    return -1;
}

#endif