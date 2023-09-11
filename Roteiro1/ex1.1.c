/*
Implemente uma funcao que receba como parametro um array de numeros reais (VET) de
tamanho N e retorne quantos numeros negativos existem nesse array. Essa funcao deve
obedecer ao cabecalho: int negativos(float *vet, int N); Teste a funcao com um programa
main.
*/
#include<stdio.h>
#include<stdlib.h>

int negativos (float*, int);
void preenche (float*, int);

int main () {
int N;
printf ("tamanho do vetor: ");
scanf ("%d", &N);
float* vet = (float*)malloc(N * sizeof(float));
printf ("digite os elementos do vetor:\n");
preenche (vet, N);
printf ("ha %d numeros negativos\n", negativos (vet, N));
return 0;
}

int negativos (float* vet, int N) {
    int cont = 0;
    for (int i = 0; i < N; i++) {
        if (vet[i] < 0) {
            cont++;
        }
    }
    return cont;
}

void preenche (float* vet, int N) {
    for (int i = 0; i < N; i++) {
    scanf ("%f", &vet[i]);
}
}

