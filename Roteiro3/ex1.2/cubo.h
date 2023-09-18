#ifndef CUBO_H
#define CUBO_H

typedef struct {
    float lado;
    float area;
    float volume;
} Cubo;

void inicializar(Cubo*);
float areaCubo (Cubo*);
float volumeCubo (Cubo*);
float ladoCubo (Cubo*);

#endif