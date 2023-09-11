/*
Escreva uma função recursiva que faça a multiplicaçao de dois números inteiros positivos de
forma recursiva. N*M = M + M + M + . . . + M (N Vezes). Teste a função com um
programa main.
*/
#include<stdio.h>

int mult (int vezes, int valor, int soma) {
    if (vezes == 0) return soma;
    return mult (vezes - 1, valor, soma + valor);
}

int main () {
    int vezes, valor, result;
    printf ("digite os numeros que deseja multiplicar: ");
    scanf ("%d %d", &vezes, &valor);
    result = mult (vezes, valor, 0);
    printf ("o resultado eh %d", result);
}