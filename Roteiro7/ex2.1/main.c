#include"menu.h"

int main () {
    MFaixa *MF = NULL;
    int opc, dim, elem, l, c;
    printf ("\n     MATRIZ DE FAIXA    \n");
    do {
        printf ("\n============== MENU ==============\n");
        printf (" 1. Criar uma nova matriz de faixa\n 2. Inserir um item\n 3. Consultar um item\n 4. Zerar a matriz\n 5. Preencher a matriz aleatoriamente\n 6. Imprimir faixas de vetores\n 7. Imprimir matriz original\n 8. Destruir matriz\n 9. Sair\n      ");
        scanf ("%d",&opc);
        switch (opc) {
            case 1: // criar nova matriz
                if (existeMFaixa(MF)) { // se ja existir, destroi
                    destroiMatriz(MF);
                }
                printf ("\nDigite a dimensao: ");
                scanf ("%d", &dim);
                MF = criaMatriz(dim);
                printf ("\nMatriz criada com sucesso!");
                break;
            case 2: // inserir
                if (existeMFaixa(MF)) {
                    printf ("\nDigite o item a ser inserido: ");
                    scanf ("%d", &elem);
                    printf ("\nDigite a linha e a coluna, respectivamente:\n");
                    scanf ("%d %d", &l, &c);
                    mensagemResultado (insereElem (MF, elem, l, c));
                } else {
                    semMFaixa();
                }
                break;
            case 3: // consultar
                if (existeMFaixa(MF)) {
                    printf ("\nDigite a linha e a coluna, respectivamente:\n");
                    scanf ("%d %d", &l, &c);
                    mensagemResultado (consultaElem (MF, l, c));
                } else {
                    semMFaixa();
                }
                break;
            case 4: // zerar a matriz
                if (existeMFaixa(MF)) {
                    zeraMatriz (MF);
                    printf ("\nMatriz zerada!");
                } else {
                    semMFaixa();
                }
                break;
            case 5: // preencher aleatorio
                if (existeMFaixa(MF)) {
                    mensagemResultado(preencheAleatorio(MF, 0, 100));
                } else {
                    semMFaixa();
                }
                break;
            case 6: // imprimir MF
                if (existeMFaixa(MF)) {
                    imprimeFaixaVetores(MF);
                } else {
                    semMFaixa();
                }
                break;
            case 7: // imprimir matriz original
                if (existeMFaixa(MF)) {
                    imprimeFaixa(MF);
                } else {
                    semMFaixa();
                }
                break;
            case 8: // destruir
                destroiMatriz(MF);
                printf ("\nMatriz destruida com sucesso!");
                MF = NULL;
                break;
            case 9: // sair
                exit(1);
            default:
                printf ("\nOpcao invalida! Digite novamente!");
        }
    } while (opc !=9);
    return 0;
    
}