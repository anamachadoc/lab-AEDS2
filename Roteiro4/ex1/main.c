#include "est.h"

int main(){
    Lista *L;
    L = criaLista();
    int v[7] = {45, 3, 99, 17, 65, 33, 28};
    for (int i = 0; i < 7; i++) {
        insereOrdenada (L, v[i]);
    }
    imprimeLista(L);
    printf ("removendo o elemento 3:\n");
    remocao (L, 3);
    imprimeLista(L);
    printf ("removendo o elemento 99:\n");
    remocao (L, 99);
    imprimeLista(L);
    printf ("removendo o elemento 33:\n");
    remocao (L, 33);
    imprimeLista(L);
    printf ("o tamanho da lista eh %d\n", L->qtd);
    destroiLista(L);
    return 0;