/* Escreva uma função recursiva que imprima os elementos de um vetor de letras em ordem
decrescente. Teste a função com um programa main. */
#include <stdio.h>
#include<stdlib.h>
char imprime (char*, int);

int main () {
    char vet[6];
    printf ("digite o vetor: ");
    scanf ("%s", &vet);
    /*printf ("digite o tamanho do vetor: ");
    scanf ("%d", &tam);
    vet =(char*)malloc(sizeof(char) * tam);
    printf ("digite os elementos do vetor:\n");
    for (int i = 0; i < tam; i++) {
        scanf ("%c", vet[i]);
        fflush (stdin);
    }*/
    imprime (vet, 6);
}

char imprime (char* vet, int tam) {
    if (tam == 0) {
        printf ("%c ", vet[0]);
        return vet[0];
    }
    printf ("%c ", vet[tam-1]);
    return imprime (vet, tam-2);
}