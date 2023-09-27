#include"LSE.h"


int main(){
    Lista *L;
    L = criaLista();
    imprimeLista(L);
    insereFim(L, 10);
    imprimeLista(L);
    insereFim(L, 20);
    insereFim(L, 30);
    imprimeLista(L);
    removeIni(L);
    imprimeLista(L);
    destroiLista(L);
    return 0;
}
