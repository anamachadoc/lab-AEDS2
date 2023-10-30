#include <stdio.h>
#include "MSD.h"

int main(){
    Matriz *M;
    M = criaMatriz(2, 2);
    imprime(M);
    preencheAleatorio(M, 1, 10);
    imprime(M);

    Matriz *A;
    A = criaMatriz(3, 3);
    int i, j, e;
    printf ("Digite os elementos da matriz:\n");
    for(i=0; i<3; i++)
        for(j=0; j<3; j++){
            scanf("%d", &e);
            insereElem(A, e, i, j);
        }

    printf ("\n");
    imprime(A);
    if(e_Simetrica(A)) printf("Simetrica!\n");
    else printf("Nao eh Simetrica!\n");

    Matriz *TS, *TI, *D, *T;

    TS = criaTriangularSup(M);
    TI = criaTriangularInf(M);
    D = criaDiagonal(M);
    T = criaTransposta(M);

    printf("Triangular Sup:\n"); imprime(TS);
    printf("Triangular Inf:\n"); imprime(TI);
    printf ("Diagonal:\n"); imprime(D);
    printf("Transposta:\n"); imprime(T);

    int p;
    consultaElem(M, &p, 0, 1);
    printf ("O elemento na posição M[0][1] eh %d\n", p);

    printf ("M eh uma matriz quadrada?\n");
    if (e_matrizQuadrada(M)) { 
        printf ("Sim!\n");
    } else {
        printf ("Não!\n");
    }

    Matriz *U = criaMatriz(2,2);
    preencheAleatorio(U, 0, 10); 
    printf ("\nMatriz auxiliar U:\n");
    imprime(U);

    Matriz *OP = criaMatriz(2,2);

    printf ("M + U:\n");
    somaMatrizes(M, U, OP); 
    imprime(OP);
    zeraMatriz(OP);

    printf ("M - U:\n");
    subMatrizes(M, U, OP);
    imprime(OP);
    zeraMatriz(OP);

    printf ("M * U:\n");
    multMatrizes(M, U, OP);
    imprime(OP);

    destroiMatriz(OP);
    destroiMatriz(A);
    destroiMatriz(TS);
    destroiMatriz(TI);
    destroiMatriz(D);
    destroiMatriz(T);
    destroiMatriz(M);
    destroiMatriz(U);
    return 0;
}