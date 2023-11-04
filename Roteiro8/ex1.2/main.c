#include"menu.h"

int main () {
    int opc, nos;
    Aluno Al;
    char nomePesquisa[20];
    ABP* A = NULL;
    printf ("\n     ARVORE ABP DE ALUNOS    \n");
    do {
        printf ("\n============== MENU ==============\n");
        printf (" 1. Criar ABP\n 2. Inserir um aluno\n 3. Buscar um aluno e imprimir suas informacoes\n 4. Remover um aluno\n 5. Imprimir a ABP em ordem\n 6. Imprimir as informacoes do aluno com maior nota\n 7. Imprimir as informacoes do aluno com menor nota\n 8. Destruir a ABP\n 9. Sair\n      ");
        scanf ("%d",&opc);
        switch (opc) {
            case 1: // criar ABP
                if (existeABP(A)) { // se ja existir, destroi
                    destroiABP(A);
                }
                A = criaABP();
                printf ("\nABP criada com sucesso!");
                break;
            case 2: // inserir aluno
                if (existeABP(A)) {
                    Al = infoAluno();
                    mensagemResultado (insereElem(A, Al));
                } else {
                    semABP();
                }
                break;
            case 3: // buscar aluno
                if (existeABP(A)) {
                    limpar ();
                    reiniciarAluno (&Al);
                    printf ("\nDigite o nome do aluno a ser pesquisado: ");
                    fgets (Al.nome, 20, stdin);
                    limpar ();
                    if (pesquisa(A, &Al)) {
                        imprimeAluno (Al);
                    } else {
                        printf ("\nO aluno nao esta na ABP!");
                    }
                } else {
                    semABP();
                }
                break;
            case 4: // remover aluno
                if (existeABP(A)) {
                    limpar ();
                    reiniciarAluno (&Al);
                    printf ("\nDigite o nome do aluno a ser removido: ");
                    fgets (Al.nome, 20, stdin);
                    mensagemResultado (removeElem(A, Al));
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
            case 6: // imprimir maior nota
                if (existeABP(A)) {
                    reiniciarAluno (&Al);
                    maiorNota (*A, &Al);
                    imprimeAluno (Al);
                } else {
                    semABP();
                }
                break;
            case 7: // imprimir menor nota
                if (existeABP(A)) {
                    reiniciarAluno (&Al);
                    menorNota (*A, &Al);
                    imprimeAluno (Al);
                } else {
                    semABP();
                }
                break;
            case 8: // destruir
                destroiABP(A);
                printf ("\nABP destruida com sucesso!");
                A = NULL;
                reiniciarAluno (&Al);
                break;
            case 9:
                exit(1);
            default:
                printf ("\nOpcao invalida! Digite novamente!");
        }
    } while (opc != 9);
    return 0;
    
}