/*
Escreva uma função recursiva que retorne a soma dos numeros de um intervalo partindo-se
sempre do maior numero e terminando no menor. Teste a função com um programa main.
*/
#include<stdio.h>
#include<math.h>

int soma (int, int, int);

int main () {
    int num1, num2, result;
    printf ("digite dois numeros:\n");
    scanf ("%d %d", &num1, &num2);
    if (num1 < num2) {
        result = soma (num1, num2, 0);
    } else {
        result = soma (num2, num1, 0);
    }
    printf ("a soma do intervalo eh %d", result);
    return 0;
}

int soma (int menor, int maior, int aux) {
    if (menor == maior) return aux + menor;
    return soma (menor + 1, maior, aux + menor);

}