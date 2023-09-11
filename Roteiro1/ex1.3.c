/*
Implemente uma funcao que receba um vetor de Alunos (Nome, matricula e Nota) e imprima
todas as informacoes do struct do Aluno que possui a maior nota e todas as informacoes do
aluno que possui a menor nota. Teste a funcao com um programa main.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char nome[20];
    int matricula;
    float nota;
}Alunos;

Alunos* ordenaNotas(Alunos*, int);
void imprime (Alunos*, int);

int main () {
    int numAlunos;
    printf ("numero de alunos: ");
    scanf ("%d", &numAlunos);
    Alunos* aluno = (Alunos*)malloc(numAlunos * sizeof(Alunos));
    for (int i = 0; i < numAlunos; i++) {
        printf ("aluno %d: \nnome: ", i+1);
        scanf ("%s", aluno[i].nome);
        __fpurge(stdin);
        printf ("numero de matricula: ");
        scanf ("%d", &aluno[i].matricula);
        __fpurge(stdin);
        printf ("nota: ");
        scanf ("%f", &aluno[i].nota);
        __fpurge(stdin);
  
    }
    imprime(aluno, numAlunos);
    return 0;
}

void imprime (Alunos *aluno, int numAlunos) {
    aluno = ordenaNotas (aluno, numAlunos);
    printf ("informacoes do aluno com maior nota:\n nome: %s\n matricula: %d\n nota: %.2f\n", aluno[numAlunos-1].nome, aluno[numAlunos-1].matricula, aluno[numAlunos-1].nota);
    printf ("informacoes do aluno com menor nota:\n nome: %s\n matricula: %d\n nota: %.2f\n", aluno[0].nome, aluno[0].matricula, aluno[0].nota);
}

Alunos* ordenaNotas (Alunos *aluno, int numALunos) { // ordena utilizando heapsort
   int i = numALunos / 2, pai, filho;
   Alunos temp;
   while(1) {
      if (i > 0) {
          i--;
          temp = aluno[i];
      } else {
          numALunos--;
          if (numALunos <= 0) {
            return aluno; 
          }
          temp = aluno[numALunos];
          aluno[numALunos] = aluno[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < numALunos) {
          if ((filho + 1 < numALunos)  &&  ((aluno[filho + 1]).nota > (aluno[filho]).nota))
              filho++;
          if ((aluno[filho]).nota > temp.nota) {
             aluno[pai] = aluno[filho];
             pai = filho;
             filho = 2*pai + 1;
          } else {
             break;
          }
      }
      aluno[pai] = temp;
   }
   return aluno;
}

