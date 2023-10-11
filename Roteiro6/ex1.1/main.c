#include"menu.h"

int main(){
    int opc; 
    int* verElem;
    Deque *dq = NULL;
    printf ("\n     DEQUE SEQUENCIAL ESTATICO    \n");
    do {
        printf ("\n============== MENU ==============\n");
        printf ("• 1 - Criar Deque\n• 2 - Inserir um item no fim;\n• 3 - Inserir um item no inicio;\n• 4 - Ver o inicio do Deque.\n• 5 - Ver o fim do Deque.\n• 6 - Remover um item do fim;\n• 7 - Remover um item do inicio;\n• 8 - Imprimir o Deque;\n• 9 - Destruir o Deque;\n• 10 - Sair;\n");
        scanf ("%d",&opc);
        switch (opc) {
            case 1: // criar deque
                if (existeDeque(dq)) { // se ja existir um deque, destroi
                    destroiDeque(dq);
                }
                dq = criaDeque();
                printf (" - Deque criado com sucesso!\n");
                break;
            case 2: // inserir item no fim
                insercao (dq, 0);
                break;
            case 3: // inserir item no inicio
                insercao (dq, 1);
                break;
            case 4: // ver inicio do deque
                if (existeDeque(dq)) {
                    if(verInicio (dq, verElem)) {
                        printf (" - Inicio do deque: %d\n", *verElem);
                    } else {
                        printf (" - Deque vazio!\n");
                    }
                } else {
                    semDeque();
                }
                break;
            case 5: // ver fim do deque
                if (existeDeque(dq)) {
                    if(verFim (dq, verElem)) {
                        printf (" - Inicio do deque: %d\n", *verElem);
                    } else {
                        printf (" - Deque vazio!\n");
                    }
                } else {
                    semDeque();
                }
                break;
            case 6: // remover do fim
                remocao (dq, 0);
                break;
            case 7: // remover do inicio
                remocao (dq, 1);
                break;
            case 8: // imprimir
                if (existeDeque(dq)) {
                    imprime(dq);
                } else {
                    semDeque();
                }
                break;
            case 9: // destruir
                if (existeDeque(dq)) {
                    destroiDeque(dq);
                    printf (" - Deque destruido!\n");
                } else {
                    semDeque();
                }
                break;
            default:
                printf (" - Opcao invalida! Digite novamente!\n");
        }
    } while (opc != 7);
    return 0;
}