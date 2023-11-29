#include"ordenaDecrescente.h"

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
    printf ("Elementos ordenados decrescentemente com SelectionSort:\n ");
    int *vS = (int*)malloc (N * sizeof(int));
    vS = copiaVetor(v, N);
    SelectionSort (vS, N, &comp, &mov);
    imprimeVetor (vS, N);
    printf ("%d movimentacoes - %d comparacoes\n", mov, comp);

    zerarCompMov (&comp, &mov);
    printf ("Elementos ordenados decrescentemente com InsertionSort:\n ");
    int *vI = (int*)malloc (N * sizeof(int));
    vI = copiaVetor(v, N);
    InsertionSort (vI, N, &comp, &mov);
    imprimeVetor (vI, N);
    printf ("%d movimentacoes - %d comparacoes\n", mov, comp);

    zerarCompMov (&comp, &mov);
    printf ("Elementos ordenados decrescentemente com BubbleSort:\n ");
    int *vB = (int*)malloc (N * sizeof(int));
    vB = copiaVetor(v, N);
    BubbleSort (vB, N, &comp, &mov);
    imprimeVetor (vB, N);
    printf ("%d movimentacoes - %d comparacoes\n", mov, comp);

    return 0;
}