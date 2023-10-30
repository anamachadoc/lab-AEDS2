#include"menu.h"

int main () {
    MEsparsaCSR *CSR = NULL;
    MEsparsaCSR *M;
    Matriz *nova;
    int opc, l, c, elem;
    printf ("\n     MATRIZ CSR    \n");
    do {
        printf ("\n============== MENU ==============\n");
        printf (" 1. Criar uma nova matriz CSR\n 2. Inserir um item\n 3. Consultar um item\n 4. Remover um item\n 5. Transformar em CSR\n 6. Imprimir vetores\n 7. Imprimir matriz esparsa\n 8. Destruir matriz\n 9. Sair\n      ");
        scanf ("%d",&opc);
        switch (opc) {
            case 1: // criar nova matriz
                if (existeMEsparsaCSR(CSR)) { // se ja existir, destroi
                    destroiMatrizEsparsa(CSR);
                }
                printf ("\nDigite o numero de linhas e de colunas, respectivamente:\n ");
                scanf ("%d %d", &l, &c);
                CSR = criaMatrizEsparsa(l, c, 0);
                printf ("\nMatriz criada com sucesso!");
                break;
            case 2: // inserir
                if (existeMEsparsaCSR(CSR)) {
                    printf ("\nDigite o item a ser inserido: ");
                    scanf ("%d", &elem);
                    printf ("\nDigite a linha e a coluna, respectivamente:\n");
                    scanf ("%d %d", &l, &c);
                    mensagemResultado (insereElemEsparsa (CSR, elem, l, c));
                } else {
                    semMEsparsaCSR ();
                }
                break;
            case 3: // consultar
                if (existeMEsparsaCSR(CSR)) {
                    printf ("\nDigite a linha e a coluna, respectivamente:\n");
                    scanf ("%d %d", &l, &c);
                    elem = consultaElemEsparsa (CSR, l, c);
                    if (elem != 0) {
                        printf("\nO elemento eh %d", elem); 
                    }
                } else {
                    semMEsparsaCSR ();
                }
                break;
            case 4: // remover
                if (existeMEsparsaCSR(CSR)) {
                    printf ("\nDigite a linha e a coluna de onde remover:\n");
                    scanf ("%d %d", &l, &c);
                    mensagemResultado (removeElemEsparsa (CSR, l, c));
                } else {
                    semMEsparsaCSR ();
                }
                break;
            case 5: // trnsformar em CSR
                /*nova = criaMatriz(3,3);
                preencheAleatorio(nova, 1,50);
                imprime(nova);
                M = transformarEmCSR(nova);
                imprimeEsparsa (M);*/
                printf ("\nEssa funcao esta com funcionamento comprometido e, por isso, esta em comentario!");
                break; 
            case 6: // imprimir vetores
                if (existeMEsparsaCSR(CSR)) {
                    imprimeEsparsaVetores(CSR);
                } else {
                    semMEsparsaCSR ();
                }
                break;
            case 7: // imprimir CSR
                if (existeMEsparsaCSR(CSR)) {
                    imprimeEsparsa(CSR);
                } else {
                    semMEsparsaCSR ();
                }
                break;
            case 8: // destruir
                destroiMatrizEsparsa(CSR);
                printf ("\nMatriz destruida com sucesso!");
                CSR = NULL;
                break;
            case 9: // sair
                exit(1);
            default:
                printf ("\nOpcao invalida! Digite novamente!");
        }
    } while (opc !=9);
    return 0;
    
}