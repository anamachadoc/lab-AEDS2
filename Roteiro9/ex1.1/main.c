#include"menu.h"

int main () {
    int opc, nos, confere;
    Funcionario func;
    AVL* A = NULL;
    printf ("\n     ARVORE AVL    \n");
    do {
        printf ("\n============== MENU ==============\n");
        printf (" 1. Criar AVL\n 2. Inserir um elemento\n 3. Buscar um elemento\n 4. Remover um elemento\n 5. Imprimir a AVL em ordem\n 6. Mostrar a quantidade de nos da AVL\n 7. Destruir a AVL\n 8. Sair\n      ");
        scanf ("%d",&opc);
        switch (opc) {
            case 1: // criar AVL
                if (existeAVL(A)) { // se ja existir, destroi
                    destroiAVL(A);
                }
                A = criaAVL();
                printf ("\nAVL criada com sucesso!");
                break;
            case 2: // inserir
                if (existeAVL(A)) {
                    zerarNos (&confere);
                    numNos (*A, &confere);
                    func = infoFunc ();
                    insereElem(A, elem);
                    zerarNos (&nos);
                    numNos (*A, &nos);
                    if (nos == (confere + 1)) {
                        mensagemResultado(1);
                    } else {
                        mensagemResultado(0);
                    }
                } else {
                    semAVL();
                }
                break;
            case 3: // buscar
                if (existeAVL(A)) {
                    printf ("\nDigite o elemento a ser pesquisado: ");
                    scanf ("%d", &elem);
                    if (pesquisa(A, elem)) {
                        printf ("\nO elemento esta na AVL!");
                    } else {
                        printf ("\nO elemento nao esta na AVL!");
                    }
                } else {
                    semAVL();
                }
                break;
            case 4: // remover
                if (existeAVL(A)) {
                    printf ("\nDigite o elemento a ser removido: ");
                    scanf ("%d", &elem);
                    mensagemResultado (removeElem(A, elem));
                } else {
                    semAVL();
                }
                break;
            case 5: // imprimir AVL em ordem
                if (existeAVL(A)) {
                    em_ordem(*A, 0);
                } else {
                    semAVL();
                }
                break; 
            case 6: // quantidade de nos
                if (existeAVL(A)) {
                    zerarNos (&nos);
                    numNos(*A, &nos);
                    printf ("\nA quantidade de nos da AVL eh %d", nos);
                } else {
                    semAVL();
                }
                break;
            case 7: // destruir
                destroiAVL(A);
                printf ("\nAVL destruida com sucesso!");
                A = NULL;
                break;
            case 8:
                exit(1);
            default:
                printf ("\nOpcao invalida! Digite novamente!");
        }
    } while (opc != 8);
    return 0;
    
}