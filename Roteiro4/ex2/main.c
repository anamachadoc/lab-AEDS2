#include"LSE.h"

int main(){
    Lista *L;
    int v[10] = {15, 8, 2, 6, 9, 21, 3, 90, 1, 0};
    L = criaLista();
    for (int i =0; i < 10; i++) {
        insereOrdenada (L, v[i]);
    }
    imprimeLista (L);
    printf ("removendo o numero 8:\n");
    remocao (removeElem (L, 8));
    imprimeLista (L);
    printf ("removendo o numero 90:\n");
    remocao (removeElem (L, 90));
    imprimeLista (L);
    printf ("removendo o numero 0:\n");
    remocao (removeElem (L, 0));
    imprimeLista (L);
    printf ("tentando remover o numero 37, que nao esta na lista:\n");
    remocao (removeElem (L, 37));
    imprimeLista (L);
    destroiLista(L);
    return 0;
}