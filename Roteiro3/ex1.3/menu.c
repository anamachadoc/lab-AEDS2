#include<stdio.h>
#include<stdlib.h>
#include"menu.h"

void menuUsuario () {
    int opc = 0;
    elemento elem;
    Conjunto* conj;
    Conjunto A, B;
    while(opc != 14) {    
        setbuf (stdin, NULL);
        printf ("\n======================== MENU ========================\n");
        printf (" 1. Criar conjunto\n 2. Inserir elemento\n 3. Remover elemento\n 4. Uniao de conjuntos\n 5. Interseccao de conjuntos\n 6. Diferenca de conjuntos\n 7. Verificar se um elemento pertence ao conjunto\n 8. Menor elemento do conjunto\n 9. Maior elemento do conjunto\n 10. Verificar se conjuntos sao iguais\n 11. Tamanho do conjunto\n 12. Verificar conjunto vazio\n 13. Imprimir conjunto\n 14. Encerrar\n     ");
        scanf ("%d", &opc);
        switch (opc) {
            case 1:
                conj = criarConjunto ();
                printf ("\nconjunto criado!");
                break;
            case 2:
                printf ("\n digite o elemento a ser inserido: ");
                scanf ("%d", &elem);
                if (inserirElemento (conj, elem) == 1) {
                    printf ("\nelemento inserido!");
                } else {
                    printf ("\nesse elemento ja esta no conjunto!");
                }
                break;
            case 3:
                printf ("\ndigite o elemento a ser removido: ");
                scanf ("%d", &elem);
                if (removerElemento (conj, elem) == 1) {
                    printf ("\nelemento removido!");
                } else {
                    printf ("\nesse elemento NAO esta no conjunto!");
                }
                break;
            case 4:
                A = defineConjunto ();
                printf ("\nconjunto A definido!");
                B = defineConjunto ();
                printf ("\nconjunto B definido!");
                uniaoConjuntos (conj, A, B);
                break;
            case 5:
                A = defineConjunto ();
                printf ("\nconjunto A definido!");
                B = defineConjunto ();
                printf ("\nconjunto B definido!");
                interseccaoConjuntos (conj, A, B);
                break;
            case 6:
                A = defineConjunto ();
                printf ("\nconjunto A definido!");
                B = defineConjunto ();
                printf ("\nconjunto B definido!");
                diferencaConjuntos (conj, A, B);
                break;
            case 7:
                printf ("\ndigite o elemento que deseja verificar: ");
                scanf ("%d", &elem);
                if (pertenceElemento (*conj, elem) == 1) {
                    printf ("\no elemento pertence ao conjunto!");
                } else {
                    printf ("\no elemento NAO pertence ao conjunto!");
                }
                break;
            case 8:
                printf ("\no menor elemento do conjunto eh %d", menorElemento(*conj));
                break;
            case 9:
                printf ("\no maior elemento do conjunto eh %d", maiorElemento(*conj));
                break;
            case 10:
                A = defineConjunto ();
                printf ("\nconjunto A definido!");
                B = defineConjunto ();
                printf ("\nconjunto B definido!");
                conjuntosIguais (A, B);
               break;
            case 11:
                printf ("\no conjunto possui %d elementos", tamanhoConjunto(*conj));
                break;
            case 12:
                conjuntoVazio (*conj);
                break;
            case 13:
                imprimirConjunto (*conj); 
                break;
            case 14:
                printf ("\nprograma encerrado!");
                break;
            default:
                printf ("\nopcao invalida!! Favor digitar novamente!");
        }
    }
}

Conjunto defineConjunto () {
    Conjunto novo;
    printf ("\n digite o tamanho do conjunto: ");
    scanf ("%d", &(novo.numElementos));
    novo.vetorElementos = (elemento*)malloc(novo.numElementos * sizeof(elemento));
    printf ("\ndigite os elementos do conjunto:\n");
    for (int i = 0; i < novo.numElementos; i++) {
        scanf ("%d", &(novo.vetorElementos[i]));
    }
    return novo;
}
