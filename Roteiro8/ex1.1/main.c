#include"menu.h"

int main () {
    int opc, elem, nos;
    ABP* A = NULL;
    printf ("\n     ARVORE ABP    \n");
    do {
        printf ("\n============== MENU ==============\n");
        printf (" 1. Criar ABP\n 2. Inserir um elemento\n 3. Buscar um elemento\n 4. Remover um elemento\n 5. Imprimir a ABP em ordem\n 6. Imprimir a ABP em pré-ordem\n 7. Imprimir a ABP em pós-ordem\n 8. Mostrar a quantidade de nós da ABP\n 9. Destruir a ABP\n 10. Sair\n      ");
        scanf ("%d",&opc);
        switch (opc) {
            case 1: // criar ABP
                if (existeABP(A)) { // se ja existir, destroi
                    destroiABP(A);
                }
                A = criaABP();
                printf ("\nABP criada com sucesso!");
                break;
            case 2: // inserir
                if (existeABP(A)) {
                    printf ("\nDigite o elemento a ser inserido: ");
                    scanf ("%d", &elem);
                    mensagemResultado (insereElem(A, elem));
                } else {
                    semABP();
                }
                break;
            case 3: // buscar
                if (existeABP(A)) {
                    printf ("\nDigite o elemento a ser pesquisado: ");
                    scanf ("%d", &elem);
                    if (pesquisa(A, elem)) {
                        printf ("\nO elemento esta na ABP!");
                    } else {
                        printf ("\nO elemento nao esta na ABP!");
                    }
                } else {
                    semABP();
                }
                break;
            case 4: // remover
                if (existeABP(A)) {
                    printf ("\nDigite o elemento a ser removido: ");
                    scanf ("%d", &elem);
                    mensagemResultado (removeElem(A, elem));
                } else {
                    semABP();
                }
                break;
            case 5: // imprimir ABP em ordem
                if (existeABP(A)) {
                    em_ordem(*A, 0);
                } else {
                    semABP();
                }
                break; 
            case 6: // pré-ordem
                if (existeABP(A)) {
                    pre_ordem(*A, 0);
                } else {
                    semABP();
                }
                break;
            case 7: // pós-ordem
                if (existeABP(A)) {
                    pos_ordem(*A, 0);
                } else {
                    semABP();
                }
                break;
            case 8: // quantidade de nos
                if (existeABP(A)) {
                    nos = 0;
                    numNos(*A, &nos);
                    printf ("\nA quantidade de nos da ABP eh %d", nos);
                } else {
                    semABP();
                }
                break;
            case 9: // destruir
                destroiABP(A);
                printf ("\nABP destruida com sucesso!");
                A = NULL;
                break;
            case 10:
                exit(1);
            default:
                printf ("\nOpcao invalida! Digite novamente!");
        }
    } while (opc != 10);
    return 0;
    
}