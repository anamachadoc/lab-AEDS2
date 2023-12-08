/*
Utilizando o c ́odigo feito na aula pr ́atica para a ordena ̧c ̃ao de um vetor de struct, adapte
esse c ́odigo para que a struct seja de um aluno com os campos (nome, matr ́ıcula e 3 notas).
Adapte o algoritmo de ordena ̧c ̃ao e busca bin ́aria, para que a busca seja realizada de 2 formas
diferentes. A primeira seria de encontrar um aluno pelo nome, e a outra de encontrar pela
matr ́ıcula. Teste o seu programa.
*/

#include"aluno.h"
#include"binaria.h"
#include"stdlib.h"

int main () {
    int numAlunos, ind;
    char nome[20];
    Aluno *aux;
    
    printf ("\nDigite o numero de alunos: ");
    scanf ("%d", &numAlunos);
    Aluno *v = (Aluno*) malloc (numAlunos * sizeof (Aluno));
    inserirAlunos(numAlunos, v);

    void QuickSortNome(v, 0, numAlunos - 1);

    printf ("\nBusque um aluno pelo nome: ");
    fgets ((*aux).nome, 20, stdin);
    printf ("\nRecursivamente:\n");
    ind = rec_buscaBinariaNome(v, 0, numAlunos - 1, aux);
    resultado(ind, aux);

    printf ("\nBusque um aluno pelo nome: ");
    fgets ((*aux).nome, 20, stdin);
    printf ("\nIterativamente:\n");
    ind = it_buscaBinariaNome(v, 0, numAlunos - 1, aux);
    resultado(ind, aux);

    return 0;
}