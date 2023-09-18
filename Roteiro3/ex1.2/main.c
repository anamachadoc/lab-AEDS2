#include"cubo.h"
#include<stdio.h>

int main () {
    Cubo c;
    inicializar (&c);
    printf ("o lado do cubo vale %.2f\n", ladoCubo (&c));
    printf ("a area do cubo vale %.2f\n", areaCubo (&c));
    printf ("o volume do cubo vale %.2f\n", volumeCubo (&c));
    return 0;
}