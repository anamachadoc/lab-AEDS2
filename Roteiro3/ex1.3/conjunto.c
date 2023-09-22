#include<stdio.h>
#include<stdlib.h>
#include"conjunto.h"


Conjunto* criarConjunto () {
    Conjunto* c = (Conjunto*)malloc(sizeof(Conjunto));
    c->numElementos = 0;
    return c; // retorna o ponteiro para o conjunto
}

int tamanhoConjunto (Conjunto C) {
    return C.numElementos;
}

void conjuntoVazio (Conjunto C) {
    if (C.numElementos == 0) {
        printf ("\nconjunto vazio!\n");
    } else {
        printf ("conjunto nao vazio: possui %d elementos\n\n", C.numElementos);
    }
}

int inserirElemento (Conjunto* C, elemento novo) {
    if (pertenceElemento((*C), novo) == 0) {
        C->numElementos++;
        C->vetorElementos = realloc(C->vetorElementos, C->numElementos * sizeof(elemento));
        C->vetorElementos[C->numElementos - 1] = novo;
        return 1;
    } else {
        return 0;
    }
}

int removerElemento (Conjunto* C, elemento retira) {
    for (int i = 0; i < C->numElementos; i++) {
        if (C->vetorElementos[i] == retira) {
            for (int j = i; j < (C->numElementos - 1); j++) {
                C->vetorElementos[j] = C->vetorElementos[j+1];
            }
            C->numElementos--;
            C->vetorElementos = realloc(C->vetorElementos, C->numElementos * sizeof(elemento));
            return 1;
        }
    }
    return 0;
}

int pertenceElemento (Conjunto C, elemento verifica) {
    for (int i = 0; i < C.numElementos; i++) {
        if (C.vetorElementos[i] == verifica) {
            return 1;
        }
    }
    return 0;
}

void uniaoConjuntos (Conjunto* uniao, Conjunto A, Conjunto B) {
    for (int i = 0; i < A.numElementos; i++) {
        inserirElemento(uniao, A.vetorElementos[i]); 
    }
    for (int i = 0; i < B.numElementos; i++) {
        if (pertenceElemento(*uniao, B.vetorElementos[i]) == 0) { // elemento ainda nao esta na uniao
            inserirElemento(uniao, B.vetorElementos[i]);
        }
    }
}
void interseccaoConjuntos (Conjunto* interseccao, Conjunto A, Conjunto B) {
    Conjunto* auxiliar = criarConjunto();
    uniaoConjuntos (auxiliar, A, B);
    for (int i = 0; i < auxiliar->numElementos; i++) {
        if (pertenceElemento (A, auxiliar->vetorElementos[i]) == 1 && pertenceElemento (B, auxiliar->vetorElementos[i]) == 1) {
            inserirElemento (interseccao, auxiliar->vetorElementos[i]);
        }
    }
}

void diferencaConjuntos (Conjunto* diferenca, Conjunto A, Conjunto B) {
    Conjunto* aux1 = criarConjunto();
    Conjunto* aux2 = criarConjunto();
    uniaoConjuntos (aux1, A, B);
    interseccaoConjuntos (aux2, A, B); 
    for (int i = 0; i < aux1->numElementos; i++) { // interseccao eh necessariamente menor ou igual a uniao
        if (pertenceElemento (*aux2, aux1->vetorElementos[i]) == 0) {
            inserirElemento (diferenca, aux1->vetorElementos[i]);
        }
    }
}

elemento menorElemento (Conjunto C) {
    elemento menor = C.vetorElementos[0];
    for (int i = 1; i < C.numElementos; i++) {
        if (menor > C.vetorElementos[i]) {
            menor = C.vetorElementos[i];
        }
    }
    return menor;
}

elemento maiorElemento (Conjunto C) {
    elemento maior = C.vetorElementos[0];
    for (int i = 1; i < C.numElementos; i++) {
        if (maior < C.vetorElementos[i]) {
            maior = C.vetorElementos[i];
        }
    }
    return maior;
}

void conjuntosIguais (Conjunto A, Conjunto B) {
    if (A.numElementos != B.numElementos) {
        printf ("\nconjuntos distintos!");
        return;
    } else {
        for (int i = 0; i < A.numElementos; i++) {
        if (pertenceElemento(B, A.vetorElementos[i]) == 0) {
            printf ("\nconjuntos distintos!");
            return;
        }
        }
    }
    printf ("\nconjuntos iguais!");
}

void imprimirConjunto (Conjunto C) {
    if (C.numElementos == 0) {
        printf ("\nconjunto vazio!");
    } else {
        for (int i = 0; i < C.numElementos; i++) {
        printf ("[%d] ", C.vetorElementos[i]);
        }
        printf ("\n");
    }
}