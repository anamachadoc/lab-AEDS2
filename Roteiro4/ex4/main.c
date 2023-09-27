#include <stdio.h>
#include "circular.h"

int main(){
    Lista *L;
    L = criaLista();
    int v[10] = {2, 37, 65, 14, 90, 52, 22, 84, 41, 100};
    for (int i = 0; i < 10; i++) {
        insereFim (L, v[i]);
    }
    imprimeLista(L);
    printf ("o tamanho da lista eh %d\n", tamanho(L));
    verifica (procura (L, 100));
    destroiLista(L);


    return 0;
}