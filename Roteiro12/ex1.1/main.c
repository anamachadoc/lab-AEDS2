#include"vetor.h"
#include"sequencial.h"
#include"binaria.h"
#include"time.h"

int main(){

    srand(time(NULL));
    comp = 0;
    clock_t seq, bin;

    int *v;
    int n, x;
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);
    v = (int*) malloc (n*sizeof(int));
    preencheAleatorio(v, n, 1, n);
    printf ("O vetor eh:\n");
    imprimeVetor(v, n);
    
    printf("Digite um elemento para busca:\n");
    scanf("%d", &x);

    int ind;

    printf ("----------- BUSCA SEQUENCIAL ----------");
    seq = clock();
    ind = buscaSequencial(v, n, x);
    seq = clock() - seq;
    printf("-----Informacoes:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)seq)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    resultado (ind);

    printf ("----------- BUSCA BINARIA ----------");
    bin = clock();
    ind = buscabinaria(v, n, x);
    bin = clock() - bin;
    printf("-----Informacoes:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)bin)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    resultado (ind);

    free(v);
    return 0;
}