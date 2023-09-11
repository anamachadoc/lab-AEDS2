#include<stdio.h>
#include"ex11.h"

int opc;

void menuUsuario () {
    while(opc != 6) {    
        printf ("\n======================== MENU ========================\n");
        printf (" 1. Criar conta\n 2. Fazer depósito\n 3. Realizar saque\n 4. Verificar saldo\n 5. Imprimir informacoes da conta\n 6. Encerrar");
        scanf ("%d", &opc);
        switch (opc) {
            case 1:
                criarConta ();
                break;
            case 2:
                fazerDeposito ();
                break;
            case 3:
                realizarSaque ();
                break;
            case 4:
                verSaldo ();
                break;
            case 5:
                break;
            default:
                printf ("Opcao invalida!! Favor digitar novamente!");
        }
    }
    exit(0);
}