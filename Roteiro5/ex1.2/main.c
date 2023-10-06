#include"menu.h"

int main(){
    int opc, elem; 
    Fila *F = NULL;
    int *inicio;
    printf ("\n     FILA SIMPLESMENTE ENCADEADA\n");
    do {
        printf ("\n============== MENU ==============\n");
        printf (" 1. Criar uma nova fila\n 2. Enfileirar um item\n 3. Ver o início da fila\n 4. Desinfileirar um item\n 5. Imprimir a fila\n 6. Destruir a fila\n 7. Sair\n      ");
        scanf ("%d",&opc);
        switch (opc) {
            case 1: // criar nova fila
                if (existeFila(F)) { // se ja existir uma fila, destroi
                    destroiFila(F);
                }
                F = criaFila();
                printf (" - Fila criada com sucesso!\n");
                break;
            case 2: // enfileirar
                if (existeFila(F)) {
                    printf ("digite o item a ser inserido: ");
                    scanf ("%d", &elem);
                    mensagemResultado (enfileirar (F, elem));
                } else {
                    semFila();
                }
                break;
            case 3: // ver inicio da fila
                if (existeFila(F) == 1) {
                    if (verInicio (F, inicio)) {
                        printf ("inicio da fila: %d\n", *inicio);
                    } else {
                        printf ("Fila vazia!\n");
                    }
                } else {
                    semFila();
                }
                break;
            case 4: // desenfileirar
                if (existeFila(F) == 1) {
                    mensagemResultado (desenfileirar (F));
                } else {
                    semFila();
                }
                break;
            case 5: // imprimir
                if (existeFila(F) == 1) {
                    imprime (F);
                } else {
                    semFila();
                }
                break;
            case 6:
                if (existeFila(F) == 1) {
                    destroiFila(F);
                    printf (" - Fila destruida com sucesso!\n");
                    F = NULL;
                } else {
                    semFila();
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