#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(Pessoa* a, Pessoa *b){
	Pessoa aux;
    strcpy (aux.nome, (*a).nome);
    aux.idade = (*a).idade;
    strcpy ((*a).nome, (*b).nome);
    (*a).idade = (*b).idade;
	strcpy ((*b).nome, aux.nome);
    (*b).idade = aux.idade;
} 

void SelectionSortCrescente(Pessoa *v, int n){
  int i, j, menor, comparacao;
  for(i=0; i < n-1; i++){
    menor = i;
    for(j=i+1; j < n; j++){
        comparacao = strcmp (v[j].nome, v[menor].nome);
       if (comparacao < 0) {
        menor = j;
       } else if (comparacao == 0 && v[j].idade < v[menor].idade) {
        menor = j;
       }
    }
    if(i != menor){
      troca(&v[i], &v[menor]);
    }
  }
}

void SelectionSortDecrescente(Pessoa *v, int n){
  int i, j, menor, comparacao;
  for(i=0; i < n-1; i++){
    menor = i;
    for(j=i+1; j < n; j++){
        comparacao = strcmp (v[j].nome, v[menor].nome);
       if (comparacao > 0) {
        menor = j;
       } else if (comparacao == 0 && v[j].idade > v[menor].idade) {
        menor = j;
       }
    }
    if(i != menor){
      troca(&v[i], &v[menor]);
    }
  }
}

void InsertionSortCrescente(Pessoa *v, int n){
  int i, j;
  Pessoa atual;
  for(i=1; i < n; i++){
    strcpy(atual.nome, v[i].nome);
    atual.idade = v[i].idade;
    for(j = i; (j > 0) && (strcmp(atual.nome, v[j-1].nome) < 0); j--) {
        strcpy (v[j].nome, v[j-1].nome);
        v[j].idade = v[j-1].idade;
    }
    if (strcmp(atual.nome, v[j-1].nome) == 0 && atual.idade < v[j-1].idade) {
        strcpy (v[j].nome, atual.nome);
        v[j].idade = atual.idade;
    }
    strcpy (v[j].nome, atual.nome);
    v[j].idade = atual.idade;
  }
}

void InsertionSortDecrescente(Pessoa *v, int n){
  int i, j;
  Pessoa atual;
  for(i=1; i < n; i++){
    strcpy(atual.nome, v[i].nome);
    atual.idade = v[i].idade;
    for(j = i; (j > 0) && (strcmp(atual.nome, v[j-1].nome) > 0); j--) {
        strcpy (v[j].nome, v[j-1].nome);
        v[j].idade = v[j-1].idade;
    }
    if (strcmp(atual.nome, v[j-1].nome) == 0 && atual.idade > v[j-1].idade) {
        strcpy (v[j].nome, v[j-1].nome);
        v[j].idade = v[j-1].idade;
    }
    strcpy (v[j].nome, atual.nome);
    v[j].idade = atual.idade;
  }
}