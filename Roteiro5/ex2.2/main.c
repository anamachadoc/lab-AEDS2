#include"menu.h"

int main(){
    int opc, elem; 
    Pilha *P = NULL;
    int *topo;
    printf ("\n     PILHA SIMPLESMENTE ENCADEADA    \n");
    do {
        printf ("\n============== MENU ==============\n");
        printf (" 1. Criar uma nova pilha\n 2. Empilhar um item\n 3. Ver o topo da pilha\n 4. Desempilhar um item\n 5. Imprimir a pilha\n 6. Destruir a pilha\n 7. Sair\n      ");
        scanf ("%d",&opc);
        switch (opc) {
            case 1: // criar nova pilha
                if (existePilha(P)) { // se ja existir uma pilha, destroi
                    destroiPilha(P);
                }
                P = criaPilha();
                printf (" - Pilha criada com sucesso!\n");
                break;
            case 2: // empilhar
                if (existePilha(P)) {
                    printf ("digite o item a ser inserido: ");
                    scanf ("%d", &elem);
                    mensagemResultado (empilhar (P, elem));
                } else {
                    semPilha();
                }
                break;
            case 3: // ver topo da pilha
                if (existePilha(P)) {
                    if (verTopo (P, topo)) {
                        printf ("topo da pilha: %d\n", *topo);
                    } else {
                        printf ("Pilha vazia!\n");
                    }
                } else {
                    semPilha();
                }
                break;
            case 4: // desempilhar
                if (existePilha(P)) {
                    mensagemResultado (desempilhar (P));
                } else {
                    semPilha();
                }
                break;
            case 5: // imprimir
                if (existePilha(P)) {
                    imprime (P);
                } else {
                    semPilha();
                }
                break;
            case 6:
                if (existePilha(P)) {
                    destroiPilha(P);
                    printf (" - Pilha destruida com sucesso!\n");
                    P = NULL;
                } else {
                    semPilha();
                }
                break;
            case 7:
                exit(1);
            default:
                printf (" - Opcao invalida! Digite novamente!");
        }
    } while (opc != 7);
    return 0;
}