/*
Implemente um programa que preenche dois vetores diferentes com numero aleatorios ( rand()
) e que contenha 3 funcoes: (a) Retorna o maior elemento do vetor; (b) Retorna o menor
elemento do vetor e (c) Retorna a media dos elementos do vetor. Teste a funcao com um
programa main.
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int maior (int*, int);
int menor (int*, int);
float media (int*, int);
void preenche (int*, int);

int main () {
    int tam1, tam2;
    printf ("tamanhos dos dois vetores: ");
    scanf ("%d %d", &tam1, &tam2);
    int* vet1 = (int*)malloc(tam1 * sizeof(int));
    int* vet2 = (int*)malloc(tam2 * sizeof(int));
    srand(time(NULL));
    preenche (vet1, tam1);
    preenche (vet2, tam2);
    printf ("os maiores elementos dos vetores 1 e 2 sao respectivamente %d e %d\n", maior(vet1, tam1), maior(vet2, tam2));
    printf ("os menores elementos dos vetores 1 e 2 sao respectivamente %d e %d\n", menor(vet1, tam1), menor(vet2, tam2));
    printf ("as medias elementos dos vetores 1 e 2 sao respectivamente %f e %f\n", media(vet1, tam1), media(vet2, tam2));
    return 0;
}


int maior (int* vet, int tam) {
    int maior = vet[0];
    for (int i = 1; i < tam; i++) {
        if (maior < vet[i]) {
            maior = vet[i];
        }
    }
    return maior;
}

int menor (int* vet, int tam) {
    int menor = vet[0];
    for (int i = 1; i < tam; i++) {
        if (menor > vet[i]) {
            menor = vet[i];
        }
    }
    return menor;
}

float media (int* vet, int tam) {
    float media = 0;
    for (int i = 0; i < tam; i++) {
        media =+ vet[i];
    }
    media /= tam;
    return media;
}

void preenche (int* vet, int tam) {
    for (int i = 0; i < tam; i++) {
    vet[i] = rand()%100;
}
}
