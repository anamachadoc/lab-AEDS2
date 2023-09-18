#include<stdio.h>
#include"cubo.h"

void inicializar(Cubo* c) {
    c->lado = 0;
    c->area = 0;
    c->volume = 0;
}

float ladoCubo (Cubo* c) {
    printf ("\ndigite o valor do lado do cubo: ");
    scanf ("%f", &(c->lado));
}

float areaCubo (Cubo* c) {
    c->area = 6 * c->lado * c->lado;
}

float volumeCubo (Cubo* c) {
    c->volume = c->lado * c->lado * c->lado;
}
