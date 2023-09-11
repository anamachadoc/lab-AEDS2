/*
Escreva uma funcao recursiva que mostre na tela os numeros inteiros de 1 a 5 em ordem
crescente. Outra para imprimir em ordem decrescente. Teste a funcao com um programa
main.
*/
#include<stdio.h>

void crescente (int num) {
    if (num > 5) return;
    printf ("%d ", num);
    crescente (num + 1);
}

void decrescente (int num) {
    if (num < 1) return;
    printf ("%d ", num);
    decrescente (num - 1);
}

int main () {
    printf ("ordem crescente: ");
    crescente(1);
    printf ("\nordem decrescente: ");
    decrescente(5);
    return 0;
}