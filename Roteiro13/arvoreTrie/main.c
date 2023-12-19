#include <stdio.h>
#include "trie.h"


int main(){
	char chaves[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
	char saida[][32] = {"Nao encontrada na TRIE", "Encontrada na TRIE"};

	NO *raiz = criaNO();
	// Construir a trie
	int i;
	for (i = 0; i < 8; i++)
		inserir(raiz, chaves[i]);
    printf ("---- ARVORE APOS INSERCAO\n");
    imprimeTrie(raiz);

	// Buscar por diferentes chaves
    printf ("---- REALIZANDO BUSCAS NA ARVORE\n");
	printf("%s --- %s\n", "the", saida[buscar(raiz, "the")]);
	printf("%s --- %s\n", "these", saida[buscar(raiz, "these")]);
	printf("%s --- %s\n", "their", saida[buscar(raiz, "their")]);
	printf("%s --- %s\n", "thaw", saida[buscar(raiz, "thaw")]);

    imprimeTrie(raiz);

	return 0;
}