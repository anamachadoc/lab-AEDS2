#include"buscaMat.h"

int main () {
    int numAlunos, ind;
    Aluno aux;
    
    printf ("\nDigite o numero de alunos: ");
    scanf ("%d", &numAlunos);
    Aluno *v = inserirAlunos(numAlunos);
    printf ("\nAlunos inseridos!\n");

    QuickSortMat(v, 0, numAlunos - 1);
    imprimirAluno (v, numAlunos);

    printf ("\nBusque um aluno pela matricula: ");
    scanf ("%d", &aux.matricula);
    printf ("Recursivamente:\n");
    ind = rec_buscaBinariaMat(v, 0, numAlunos - 1, &aux);
    resultado(ind, aux);

    printf ("\nBusque um aluno pela matricula: ");
    scanf ("%d", &aux.matricula);
    printf ("Iterativamente:\n");
    ind = it_buscaBinariaMat(v, 0, numAlunos - 1, &aux);
    resultado(ind, aux);

    return 0;
}