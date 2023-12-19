#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
    char nome[20];
    int matricula;
    float notas[3];
} Aluno;

Aluno* inserirAlunos (int numAlunos) {
    Aluno *v = (Aluno *)malloc(sizeof(Aluno));
    for (int i = 0; i < numAlunos; i++) {
        setbuf(stdin, NULL);
        printf ("\nDigite o nome do aluno: ");
        fgets ((v[i].nome), 20, stdin);
        setbuf(stdin, NULL);
        printf ("Digite a matricula: ");
        scanf ("%d", &v[i].matricula);
        setbuf(stdin, NULL);
        for (int j = 0; j < 3; j++) {
            printf ("Digite a nota %d: ", j + 1);
            scanf ("%f", &v[i].notas[j]);
        }
        setbuf(stdin, NULL);
    }
    return v;
}

void imprimirAluno (Aluno* v, int numAlunos) {
    for (int i = 0; i < numAlunos; i++) {
    printf ("%s  -> matricula: %d\n  -> nota 1: %f\n  -> nota 2: %f\n  -> nota 3: %f\n", v[i].nome, v[i].matricula, v[i].notas[0], v[i].notas[1], v[i].notas[2]);
    }
    printf ("\n");
}

void resultado (int ind, Aluno aux) {
    if (ind == -1) {
        printf ("\nO aluno nao foi encontrado!");
    } else {
        printf ("O aluno foi encontrado na posicao %d. As informacoes podem ser visualizadas a seguir:", ind);
        printf ("%s  -> matricula: %d\n  -> nota 1: %.2f\n  -> nota 2: %.2f\n  -> nota 3: %.2f\n", aux.nome, aux.matricula, aux.notas[0], aux.notas[1], aux.notas[2]);   
    }
}

#endif