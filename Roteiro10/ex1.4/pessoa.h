#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char nome[20];
    int idade;
} Pessoa;

void inserirPessoas (int numPessoas, Pessoa* v) {
    for (int i = 0; i < numPessoas; i++) {
        setbuf(stdin, NULL);
        printf ("Digite o nome da pessoa: ");
        fgets ((v[i].nome), 20, stdin);
        setbuf(stdin, NULL);
        printf ("Digite a idade: ");
        scanf ("%d", &v[i].idade);
        setbuf(stdin, NULL);
    }
}

void imprimir (Pessoa* v, int numPessoas) {
    for (int i = 0; i < numPessoas; i++) {
    printf ("   PESSOA %d \n  -> %s  -> %d anos\n", i + 1, v[i].nome, v[i].idade);
    }
    printf ("\n");
}