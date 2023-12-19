#include <stdio.h>
#include "hash.h"

int main(){

    Hash *Hdiv, *Hdob, *Hmult;
    Hdiv = criaHash(10);
    Hdob = criaHash(10);
    Hmult = criaHash(10);
    int busca = 1, elem, p, insere = 1;

    while(insere == 1) {
        printf ("Digite um elemento a ser inserido: ");
        scanf ("%d", &elem);
        /*
        Para testar as 3 funcoes de insercao, eh utilizado um switch case na funcao de 
        insercao, sendo (1) divisao (2) dobra (3) multiplicacao
        */
        insereHash_semTratar(Hdiv, elem, 1);
        insereHash_semTratar(Hdob, elem, 2);
        insereHash_semTratar(Hmult, elem, 3);
        printf ("Deseja inserir mais um elemento? (1) Sim (0) Nao   ");
        scanf ("%d", &insere);
    }
    printf ("\n --- HASH COM FUNCAO DE DIVISAO ---\n");
    imprimeHash(Hdiv);
    printf ("\n --- HASH COM FUNCAO DE DOBRA ---\n");
    imprimeHash(Hdob);
    printf ("\n --- HASH COM FUNCAO DE MULTIPLICACAO ---\n");
    imprimeHash(Hmult);

    while (busca == 1) {
        printf ("Digite o elemento a ser buscado nas hashs: ");
        scanf ("%d", &elem);
        if (buscaHash_semTratar(Hdiv, elem, &p, 1)) {
            printf ("\nElemento encontrado na posicao %d na hash com funcao de divisao\n", p);
        } else {
            printf ("Elemento nao encontrado na hash com funcao de divisao\n");

        }
        if (buscaHash_semTratar(Hdob, elem, &p, 2)) {
            printf ("Elemento encontrado na posicao %d na hash com funcao de dobra\n", p);
        } else {
            printf ("Elemento nao encontrado na hash com funcao de dobra\n");

        }
        if (buscaHash_semTratar(Hmult, elem, &p, 3)) {
            printf ("Elemento encontrado na posicao %d na hash com funcao de multiplicacao\n", p);
        } else {
            printf ("Elemento nao encontrado na hash com funcao de multiplicacao\n");

        }
        printf ("Deseja buscar mais um elemento? (1) Sim (0) Nao   ");
        scanf ("%d", &busca);
    }

    destroiHash(Hdiv);
    destroiHash(Hdob);
    destroiHash(Hmult);
    return 0;
}