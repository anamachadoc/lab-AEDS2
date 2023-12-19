#include"stdio.h"
#include"stdlib.h"

#ifndef LEITURAVALORES_H
#define LEITURAVALORES_H

int* lerArquivo (char *nomeArquivo) {
int numeroElementos;
FILE *file = fopen(nomeArquivo, "r");
fscanf(file, "%d", &numeroElementos);
int *vetor = (int*)malloc(numeroElementos * sizeof(int));
  for (int i = 0; i < numeroElementos; i++) {
    fscanf(file, "%d", &(vetor[i]));
  }
return vetor;  
}

#endif

