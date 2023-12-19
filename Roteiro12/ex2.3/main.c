#include <stdio.h>
#include "hashLSE.h"

int main(){

    Hash *H;
    H = criaHash(10);
    int busca = 1, i, elem, p;

    for(i=0; i < 20; i++) {
        insereHashLSE(H, i);
    }

    imprimeHash(H);

    while (busca == 1) {
        printf ("Digite o elemento a ser buscado nas hashs: ");
        scanf ("%d", &elem);
        if (buscaHashLSE(H, elem, &p)) {
            printf ("\nElemento encontrado na hash!\n");
        } else {
            printf ("Elemento nao encontrado na hash\n");
        }
        printf ("Deseja buscar mais um elemento? (1) Sim (0) Nao   ");
        scanf ("%d", &busca);
    }

    destroiHash(H);

    return 0;
}