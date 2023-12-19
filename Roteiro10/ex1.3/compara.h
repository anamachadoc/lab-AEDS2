#include"ordenacao.h"
#include"leituraValores.h"

#ifndef COMPARA_H
#define COMPARA_H

void comparacao (int numeroElementos, int *v) {
    clock_t t;
    int comp, mov;

    printf ("---- ARQUIVO COM %d NUMEROS ----\n", numeroElementos);

    printf (" -> INSERTIONSORT: \n");
    zerarCompMov (&comp, &mov);
    int *vI = (int*)malloc (numeroElementos * sizeof(int));
    vI = copiaVetor(v, numeroElementos);
    t = clock () ;
    InsertionSort (vI, numeroElementos, &comp, &mov);
    t = clock () - t;
    printf ("execucao em %f segundos\n", (( float )t)/ CLOCKS_PER_SEC );
    printf ("%d movimentacoes - %d comparacoes\n", mov, comp);

    printf (" -> SELECTIONSORT: \n");
    zerarCompMov (&comp, &mov);
    int *vS = (int*)malloc (numeroElementos * sizeof(int));
    vS = copiaVetor(v, numeroElementos);
    t = clock () ;
    SelectionSort (vS, numeroElementos, &comp, &mov);
    t = clock () - t;
    printf ("execucao em %f segundos\n", (( float )t)/ CLOCKS_PER_SEC );
    printf ("%d movimentacoes - %d comparacoes\n", mov, comp);

    printf (" -> BUBBLESORT: \n");
    zerarCompMov (&comp, &mov);
    int *vB = (int*)malloc (numeroElementos * sizeof(int));
    vB = copiaVetor(v, numeroElementos);
    t = clock () ;
    BubbleSort (vB, numeroElementos, &comp, &mov);
    t = clock () - t;
    printf ("execucao em %f segundos\n", (( float )t)/ CLOCKS_PER_SEC );
    printf ("%d movimentacoes - %d comparacoes\n", mov, comp);
}


void comparaContrario () {
    int *contrario;
    printf ("\n *** AO CONTRARIO ***\n");
    contrario = lerArquivo("input/100-contrario.txt");
    comparacao (100, contrario);
    contrario = lerArquivo("input/1000-contrario.txt");
    comparacao (1000, contrario);
    contrario = lerArquivo("input/10000-contrario.txt");
    comparacao (10000, contrario);
    contrario = lerArquivo("input/100000-contrario.txt");
    comparacao (100000, contrario);
    contrario = lerArquivo("input/1000000-contrario.txt");
    comparacao (1000000, contrario);
}

void comparaOrdenado () {
    int *ordenado;
    printf ("\n *** ORDENADO ***\n");
    ordenado = lerArquivo("input/100-ordenado.txt");
    comparacao (100, ordenado);
    ordenado = lerArquivo("input/1000-ordenado.txt");
    comparacao (1000, ordenado);
    ordenado = lerArquivo("input/10000-ordenado.txt");
    comparacao (10000, ordenado);
    ordenado = lerArquivo("input/100000-ordenado.txt");
    comparacao (100000, ordenado);
    ordenado = lerArquivo("input/1000000-ordenado.txt");
    comparacao (1000000, ordenado);
}

void comparaMisturado () {
    int *misturado;
    printf ("\n *** MISTURADO ***\n");
    misturado = lerArquivo("input/100-misturado.txt");
    comparacao (100, misturado);
    misturado = lerArquivo("input/1000-misturado.txt");
    comparacao (1000, misturado);
    misturado = lerArquivo("input/10000-misturado.txt");
    comparacao (10000, misturado);
    misturado = lerArquivo("input/100000-misturado.txt");
    comparacao (100000, misturado);
    misturado = lerArquivo("input/1000000-misturado.txt");
    comparacao (1000000, misturado);
}

void comparaQuaseOrdenado () {
    int *quaseordenado;
    printf ("\n *** QUASE ORDENADO ***\n");
    quaseordenado = lerArquivo("input/100-quaseordenado.txt");
    comparacao (100, quaseordenado);
    quaseordenado = lerArquivo("input/1000-quaseordenado.txt");
    comparacao (1000, quaseordenado);
    quaseordenado = lerArquivo("input/10000-quaseordenado.txt");
    comparacao (10000, quaseordenado);
    quaseordenado = lerArquivo("input/100000-quaseordenado.txt");
    comparacao (100000, quaseordenado);
    quaseordenado = lerArquivo("input/1000000-quaseordenado.txt");
    comparacao (1000000, quaseordenado);
}

#endif