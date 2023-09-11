/*
2.5 Faça o que se pede:
a) Faça um algoritmo recursivo para preencher as posições de um vetor de inteiros de
tamanho N.
b) Faça um algoritmo recursivo para imprimir de forma crescente, do primeiro até o  ́ultimo,
(e decrescente, do  ́ultimo até o primeiro) os elementos desse vetor.
c) Faça um algoritmo recursivo para encontrar e retornar o maior elemento desse vetor.
*/

#include <stdio.h>
#include <stdlib.h>

int* preencher (int*, int, int);
int imprimeCrescente (int*, int, int);
int imprimeDecrescente (int*, int);
int maior (int* vet, int tam, int elem);

int main () {
    int tam, cdg;
    printf ("tamanho do vetor: ");
    scanf ("%d", &tam);
    int* vet = (int*)malloc(tam * sizeof(int));
    vet = preencher (vet, tam - 1, 0);
    printf ("deseja imprimir em ordem crescente ou decrescente? 1 para crescente e 0 para decrescente");
    scanf ("%d", &cdg);
    if (cdg == 1) {
        imprimeCrescente (vet, tam - 1, 0);
    } else {
        imprimeDecrescente (vet, tam - 1);
    }
    printf ("o maior elemento eh %d", maior (vet, tam - 1, vet[tam-1]));
    return 0;
}

int* preencher (int *vet, int tam, int cont) {
    printf("digite o elemento da posicao %d ", cont + 1);
    scanf ("%d", &vet[cont]);
    if (cont == tam){
        return vet;
    }
    return preencher (vet, tam, cont + 1);   
} 

int imprimeCrescente (int* vet, int tam, int cont) {
        if (cont == tam) {
            printf ("%d ", vet[cont]);
            return 0;
        }
        printf ("%d ", vet[cont]);
        return imprimeCrescente (vet, tam, cont + 1);
}

int imprimeDecrescente (int* vet, int tam) {
    if (tam == 0) {
        printf ("%d ", vet[tam]);
        return 0;
    }
    printf ("%d ", vet[tam]);
    return imprimeDecrescente (vet, tam - 1);
}

int maior (int* vet, int tam, int elem) {
    if (vet[tam] > elem) {
        elem = vet[tam];
    }
    if (tam == 0) return elem;
    return maior(vet, tam - 1, elem);
}