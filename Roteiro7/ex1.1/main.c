#include <stdio.h>
#include "MSE.h"

int main(){
    Matriz *M;
    M = criaMatriz(2, 3);
    imprime(M);
    preencheAleatorio(M, 10, 50);
    imprime(M);

    Matriz *TS, *TI;
    TS = criaTriangularSup(M);
    TI = criaTriangularInf(M);

    printf("Triangular Sup:\n"); imprime(TS);
    printf("Triangular Inf:\n"); imprime(TI);

    Matriz* T;
    T = criaTransposta(M);
    printf("Transposta:\n"); imprime(T);

    destroiMatriz(M);
    return 0;
}