#ifndef CUBO_H
#define CUBO_H

typedef int elemento; // elemento para representar os elementos do conjunto

typedef struct {
    elemento* vetorElementos;
    int numElementos;
} Conjunto;


Conjunto* criarConjunto ();
void uniaoConjuntos (Conjunto*, Conjunto, Conjunto);
int inserirElemento (Conjunto*, elemento);
int removerElemento (Conjunto*, elemento);
void interseccaoConjuntos (Conjunto*, Conjunto, Conjunto);
void diferencaConjuntos (Conjunto*, Conjunto, Conjunto);
int pertenceElemento (Conjunto, elemento);
elemento menorElemento (Conjunto);
elemento maiorElemento (Conjunto);
void conjuntosIguais (Conjunto, Conjunto);
int tamanhoConjunto (Conjunto);
void conjuntoVazio (Conjunto);
void imprimirConjunto (Conjunto);

#endif