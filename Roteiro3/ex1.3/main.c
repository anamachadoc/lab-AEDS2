#include<stdio.h>
#include"conjunto.h"

int main () {
    Conjunto *A, *B;
    A = criarConjunto ();
    B = criarConjunto ();
    int aux1[4] = {7, 9, 3, 1};
    int aux2[6] = {2, 8, 3, 5, 1, 7};
    // inserindo aux1 em A e aux2 em B
    for (int i = 0; i < 4; i++) {
        inserirElemento (A, aux1[i]);
    }
    for (int i = 0; i < 6; i++) {
        inserirElemento (B, aux2[i]);
    }
    printf ("\nconjuntos ja existentes:\n- A: ");
    imprimirConjunto(*A);
    printf("\n- B: ");
    imprimirConjunto(*B);
    Conjunto* uniao = criarConjunto ();
    printf ("\n- uniao de A e B: ");
    uniaoConjuntos (uniao, *A, *B);
    imprimirConjunto (*uniao);
    printf ("\n- apos inserir o elemento 10 no B: ");
    inserirElemento (B, 10);
    imprimirConjunto (*B);
    printf ("\n- apos retirar o elemento 7 no A: ");
    removerElemento (A, 7);
    imprimirConjunto (*A);
    Conjunto* dif = criarConjunto ();
    printf ("\n- diferenca dos conjuntos A e B: ");
    diferencaConjuntos (dif, *A, *B);
    imprimirConjunto (*dif);
    printf ("\n- interseccao dos conjuntos A e B: ");
    Conjunto* intersec = criarConjunto ();
    interseccaoConjuntos (intersec, *A, *B);
    imprimirConjunto (*intersec);
    printf ("\n- verificando se o elemento 3 pertence ao conjunto A:\n");
    if (pertenceElemento (*A, 3) == 1) {
        printf ("o elemento pertence!\n");
    } else {
        printf ("o elemento nao pertence!\n");
    }
    printf ("\n- verificando o menor elemento no conjunto B:\n");
    printf ("o menor elemento de B eh %d\n", menorElemento (*B));
    printf ("\n- verificando o maior elemento no conjunto A:\n");
    printf ("o maior elemento de A eh %d\n", maiorElemento (*A));
    printf ("\n- verificando se A e B sao iguais:");
    conjuntosIguais (*A, *B);
    printf ("\n\n- verificando o tamanho do conjunto A:\n");
    printf ("o conjunto A possui %d elementos\n", tamanhoConjunto (*A));
    printf ("\n- verificando se B é um conjunto vazio:\n");
    conjuntoVazio (*B);
    return 0;
}