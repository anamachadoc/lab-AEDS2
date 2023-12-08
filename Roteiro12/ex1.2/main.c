#include"binaria.h"

int main(){

    srand(time(NULL));
    int comp, ind;
    clock_t bin;

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

    printf ("----------- BUSCA BINARIA ----------\n");

    comp = 0;
    QuickSort(v, 0, n-1);
    printf ("Vetor ordenado em ordem decrescente:\n");
    imprimeVetor(v, n);
    bin = clock();
    ind = rec_buscaBinaria(v, 0, n-1, x, &comp);
    bin = clock() - bin;
    printf("-----Informacoes - recursiva:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)bin)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    resultado (ind);

    comp = 0;
    bin = clock();
    ind = it_buscaBinaria(v, 0, n-1, x, &comp);
    bin = clock() - bin;
    printf("-----Informacoes - iterativa:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)bin)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);
    resultado (ind);

    free(v);
    return 0;
}