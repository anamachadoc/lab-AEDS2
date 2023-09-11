#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ex11.h"

void inicializar (contaBancaria* lista, int* tam) {
    lista->prox = NULL;
    *tam = 0;
}

void criarConta (ContaBancaria* lista, int numero, char *titular)

