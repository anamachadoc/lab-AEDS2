/*
Implemente uma funcao que calcule as raizes de uma equacao do segundo grau do tipo Ax^2
+ Bx + C = 0.
*/
#include<stdio.h>
#include<math.h>

int raizes(float, float, float, float*, float*); // retorno é o numero de raizes reais e distintas

int main () {
    float A = 0, B, C, x1, x2;
    while (A == 0) {
        printf ("digite os valores de A, B e C da funcao, lembrando que A eh necessariamente diferente de zero:\n");
        scanf ("%f %f %f", &A, &B, &C);
    }
    switch(raizes(A, B, C, &x1, &x2)) {
        case 0:
            printf ("nao ha raizes reais");
            break;
        case 1:
            printf ("ha uma raiz real: %f", x1);
            break;
        case 2:
            printf ("ha duas raizes reais: %.2f e %.2f", x1, x2);
            break;
        default:
            printf ("resultado invalido");
    }
    return 0;
}

int raizes(float A, float B, float C, float* x1, float* x2) {
    float delta = B * B - 4 * A * C;
    if (delta < 0) return 0;
    *x1 = (- B - sqrt(delta))/(2 * A);
    *x2 = (- B + sqrt(delta))/(2 * A);
    if (x1 == x2) return 1;
    else return 2;
}