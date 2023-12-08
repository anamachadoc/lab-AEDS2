#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void trocaNome (Aluno* a, Aluno *b){
	Aluno aux;
    strcpy (aux.nome, (*a).nome);
    aux.idade = (*a).idade;
    strcpy ((*a).nome, (*b).nome);
    (*a).idade = (*b).idade;
	strcpy ((*b).nome, aux.nome);
    (*b).idade = aux.idade;
} 

int particaoNome(int *v, int ini, int fim){
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

void QuickSortNome(int *v, int ini, int fim){
    if(ini < fim ){
        int q = particao(v, ini, fim);
        QuickSort(v, ini, q);
        QuickSort(v, q+1, fim);
    }
}

int rec_buscaBinariaNome(int *v, int ini, int fim, Aluno *elem){
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
            return rec_buscaBinaria(v, ini, meio-1, elem, comp); 
        else
            return rec_buscaBinaria(v, meio+1, fim, elem, comp);
    }
}

int it_buscaBinariaNome(int *v, int ini, int fim, Aluno *elem){
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
