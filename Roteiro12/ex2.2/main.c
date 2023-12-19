#include <stdio.h>
#include "hashEA.h"

int main(){

    Hash *Hlin, *Hquad, *Hdup;
    Hlin = criaHash(10);
    Hquad = criaHash(10);
    Hdup = criaHash(10);
    int busca = 1, elem, p, insere = 1;

    while(insere == 1) {
        printf ("Digite um elemento a ser inserido: ");
        scanf ("%d", &elem);
        /*
        Para testar as 3 sondagens, eh utilizado um switch case na funcao de 
        insercao, sendo (1) linear (2) quadratica (3) duplo hash
        */
        insereHash_EnderAberto(Hlin, elem, 1);
        insereHash_EnderAberto(Hquad, elem, 2);
        insereHash_EnderAberto(Hdup, elem, 3);
        printf ("Deseja inserir mais um elemento? (1) Sim (0) Nao   ");
        scanf ("%d", &insere);
    }
    printf ("\n --- HASH COM SONDAGEM LINEAR ---\n");
    imprimeHash(Hlin);
    printf ("\n --- HASH COM SONDAGEM QUADRATICA ---\n");
    imprimeHash(Hquad);
    printf ("\n --- HASH COM SONDAGEM DUPLO HASH ---\n");
    imprimeHash(Hdup);

    while (busca == 1) {
        printf ("Digite o elemento a ser buscado nas hashs: ");
        scanf ("%d", &elem);
        if (buscaHash_EnderAberto(Hlin, elem, &p, 1)) {
            printf ("\nElemento encontrado na posicao %d na hash com sondagem linear\n", p);
        } else {
            printf ("Elemento nao encontrado na hash com sondagem linear\n");
        }
        if (buscaHash_EnderAberto(Hquad, elem, &p, 2)) {
            printf ("Elemento encontrado na posicao %d na hash com sondagem quadratica\n", p);
        } else {
            printf ("Elemento nao encontrado na hash com sondagem quadratica\n");

        }
        if (buscaHash_EnderAberto(Hdup, elem, &p, 3)) {
            printf ("Elemento encontrado na posicao %d na hash com sondagem de duplo hash\n", p);
        } else {
            printf ("Elemento nao encontrado na hash com sondagem de duplo hash\n");

        }
        printf ("Deseja buscar mais um elemento? (1) Sim (0) Nao   ");
        scanf ("%d", &busca);
    }

    destroiHash(Hlin);
    destroiHash(Hquad);
    destroiHash(Hdup);
    return 0;
}