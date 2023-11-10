#include"menu.h"

int main () {
    int opc, nos, confere;
    Funcionario func;
    AVL* A = NULL;
    printf ("\n     ARVORE AVL    \n");
    do {
        printf ("\n============== MENU ==============\n");
        printf (" 1. Criar AVL\n 2. Inserir um funcionario pelo salario\n 3. Buscar um funcionario pelo salario e imprimir seus dados\n 4. Remover um funcionario pelo nome\n 5. Imprimir a AVL em ordem\n 6. Imprimir as informacoes do funcionario com o maior salario\n 7. Imprimir as informacoes do funcionario com o menor salario\n 8. Destruir a AVL\n 9. Sair\n      ");
        scanf ("%d",&opc);
        switch (opc) {
            case 1: // criar AVL
                if (existeAVL(A)) { // se ja existir, destroi
                    destroiAVL(A);
                }
                A = criaAVL();
                printf ("\nAVL criada com sucesso!");
                break;
            case 2: // inserir funcionario pelo salario
                if (existeAVL(A)) {
                    zerarNos (&confere);
                    numNos (*A, &confere);
                    func = infoFunc();
                    insereElem(A, func);
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
            case 3: // buscar funcionario pelo salario
                if (existeAVL(A)) {
                    printf ("\nDigite o salario a ser pesquisado: ");
                    scanf ("%lf", &func.salario);
                    if (pesquisa(A, &func)) {
                       imprimeFunc (func);
                    } else {
                        printf ("\nO funcionario nao esta na AVL!");
                    }
                } else {
                    semAVL();
                }
                break;
            case 4: // remover funcionario pelo nome
                if (existeAVL(A)) {
                    zerarNos (&confere);
                    numNos (*A, &confere);
                    limpar ();
                    printf ("\nDigite o elemento a ser removido: ");
                    fgets (func.nome, 20, stdin);
                    removeElem(A, func);
                    zerarNos (&nos);
                    numNos (*A, &nos);
                    if (nos == (confere - 1)) {
                        mensagemResultado(1);
                    } else {
                        mensagemResultado(0);
                    }
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
            case 6: // maior salario
                if (existeAVL(A)) {
                    maiorSalario (*A, &func);
                    imprimeFunc (func);
                } else {
                    semAVL();
                }
                break;
            case 7: // menor salario
                if (existeAVL(A)) {
                    menorSalario (*A, &func);
                    imprimeFunc (func);
                } else {
                    semAVL();
                }
                break;
            case 8: // destruir
                destroiAVL(A);
                printf ("\nAVL destruida com sucesso!");
                A = NULL;
                break;
            case 9: 
                exit(1);
            default:
                printf ("\nOpcao invalida! Digite novamente!");
        }
    } while (opc != 9);
    return 0;
    
}