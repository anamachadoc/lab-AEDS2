#include"ordenacaoDecrescente.h"

int main () {
    srand(time(NULL));
    int comp, mov;
    clock_t t;

    int N;

    printf ("Digite o numero de elementos do vetor: ");
    scanf ("%d", &N);
    int *v = (int*)malloc (N * sizeof(int));

    printf ("\nDigite os elementos do vetor:\n");
    for (int i = 0; i < N; i++) {
        scanf ("%d", &v[i]);
    }

    printf ("Elementos digitados: ");
    imprimeVetor(v, N);

    zerarCompMov (&comp, &mov);
    printf ("Elementos ordenados decrescentemente com QuickSort:\n ");
    int *vQ = (int*)malloc (N * sizeof(int));
    vQ = copiaVetor(v, N);
    QuickSort (vQ, 0, N-1, N, &comp, &mov);
    imprimeVetor (vQ, N);
    printf ("%d movimentacoes - %d comparacoes\n", mov, comp);

    zerarCompMov (&comp, &mov);
    printf ("Elementos ordenados decrescentemente com ShellSort:\n ");
    int *vS = (int*)malloc (N * sizeof(int));
    vS = copiaVetor(v, N);
    ShellSort (vS, N, &comp, &mov);
    imprimeVetor (vS, N);
    printf ("%d movimentacoes - %d comparacoes\n", mov, comp);

    zerarCompMov (&comp, &mov);
    printf ("Elementos ordenados decrescentemente com MergeSort:\n ");
    int *vM = (int*)malloc (N * sizeof(int));
    vM = copiaVetor(v, N);
    MergeSort (vM, 0, N-1, &comp, &mov);
    imprimeVetor (vM, N);
    printf ("%d movimentacoes - %d comparacoes\n", mov, comp);

    zerarCompMov (&comp, &mov);
    printf ("Elementos ordenados decrescentemente com HeapSort:\n ");
    int *vH = (int*)malloc (N * sizeof(int));
    vH = copiaVetor(v, N);
    HeapSort (vH, N, &comp, &mov);
    imprimeVetor (vH, N);
    printf ("%d movimentacoes - %d comparacoes\n", mov, comp);

    return 0;
}