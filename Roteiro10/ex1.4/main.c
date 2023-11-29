#include"pessoa.h"
#include"ordenaPessoa.h"

int main () {
    int numPessoas;
    printf ("Quantas pessoas serao ordenadas? ");
    scanf ("%d", &numPessoas);
    Pessoa* vetP = (Pessoa*) malloc (numPessoas * sizeof (Pessoa));
    inserirPessoas (numPessoas, vetP);
    imprimir (vetP, numPessoas);

    printf ("Ordem crescente com InsertionSort:\n");
    InsertionSortCrescente (vetP, numPessoas);
    imprimir (vetP, numPessoas);

    printf ("Ordem decrescente com InsertionSort:\n");
    InsertionSortDecrescente (vetP, numPessoas);
    imprimir (vetP, numPessoas);

    printf ("Ordem crescente com SelectionSort:\n");
    SelectionSortCrescente (vetP, numPessoas);
    imprimir (vetP, numPessoas);

    printf ("Ordem decrescente com SelectionSort:\n");
    SelectionSortDecrescente (vetP, numPessoas);
    imprimir (vetP, numPessoas);

    return 0;
}