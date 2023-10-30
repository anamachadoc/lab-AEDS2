#include <stdio.h>
#include "MSE.h"

int main(){
    Matriz *M;
    M = criaMatriz(3, 3);
    imprime(M);
    preencheAleatorio(M, 10, 50);
    imprime(M);

    Matriz *TS, *TI, *D, *T;

    TS = criaTriangularSup(M);
    TI = criaTriangularInf(M);
    D = criaDiagonal(M);
    T = criaTransposta(M);

    printf("Triangular Sup:\n"); imprime(TS);
    printf("Triangular Inf:\n"); imprime(TI);
    printf ("Diagonal:\n"); imprime(D);
    printf("Transposta:\n"); imprime(T);

    insereElem (M, 35, 0, 1);
    printf ("Elemento 35 inserido na posicao M[0][1]:\n"); imprime(M);

    int p;
    consultaElem(M, &p, 1, 1);
    printf ("O elemento na posição M[1][1] eh %d\n", p);

    printf ("M eh uma matriz quadrada?\n");
    if (e_matrizQuadrada(M)) { 
        printf ("Sim!\n");
    } else {
        printf ("Não!\n");
    }

    Matriz *A = criaMatriz(3,3);
    preencheAleatorio(A, 0, 10); 
    printf ("\nMatriz auxiliar A:\n");
    imprime(A);

    Matriz *OP = criaMatriz(3,3);

    printf ("M + A:\n");
    somaMatrizes(M, A, OP); 
    imprime(OP);
    zeraMatriz(OP);

    printf ("M - A:\n");
    subMatrizes(M, A, OP);
    imprime(OP);
    zeraMatriz(OP);

    printf ("M * A:\n");
    multMatrizes(M, A, OP);
    imprime(OP);

    destroiMatriz(OP);
    destroiMatriz(A);
    destroiMatriz(TS);
    destroiMatriz(TI);
    destroiMatriz(D);
    destroiMatriz(T);
    destroiMatriz(M);
    return 0;
}