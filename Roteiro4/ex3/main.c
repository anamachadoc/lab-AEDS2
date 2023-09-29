#include <stdio.h>
#include "LDE.h"

int main(){
    Lista *L;
    L = criaLista();
    int v[10] = {2, 65, 33, 78, 10, 49, 58, 13, 6, 53};
    for (int i = 0; i < 10; i++) {
        insereOrdenada(L, v[i]);
    }
    imprimeLista(L);
    printf ("o tamanho da lista eh %d\n", tamanho(L));
    printf ("removendo o elemento 2 da lista:\n");
    remocao (removeElem (L, 2));
    imprimeLista(L);
    printf ("removendo o elemento 49 da lista:\n");
    remocao (removeElem (L, 49));
    imprimeLista(L);
    printf ("removendo o elemento 78 da lista:\n");
    remocao (removeElem (L, 78));
    imprimeLista(L);
    printf ("tentando remover o elemento 1, que nao esta na lista:\n");
    remocao (removeElem (L, 1));
    imprimeLista(L);
    destroiLista(L);
    return 0;
}