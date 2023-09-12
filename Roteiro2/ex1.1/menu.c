#include<stdio.h>
#include<stdlib.h>
#include"menu.h"

int opc = 0;

void menuUsuario (contaBancaria* conta) {
    contaBancaria nova;
    double saldo;
    while(opc != 6) {    
        printf ("\n======================== MENU ========================\n");
        printf (" 1. Criar conta\n 2. Fazer depósito\n 3. Realizar saque\n 4. Verificar saldo\n 5. Imprimir informacoes da conta\n 6. Encerrar\n\n");
        scanf ("%d", &opc);
        switch (opc) {
            case 1:
                nova = dadosCliente();
                criarConta (conta, nova.numeroConta, nova.titular);
                printf ("conta criada!\n");
                break;
            case 2:
                depositar (conta, quantia());
                break;
            case 3:
                sacar (conta, quantia());
                break;
            case 4:
                saldo = consultarSaldo (conta);
                printf ("saldo da conta %d: %.2lf\n", conta->numeroConta, saldo);
                break;
            case 5:
                imprimirInfo(conta);
                break;
            case 6:
                free (conta);
                printf ("programa encerrado!\n");
                exit(1);
            default:
                printf ("Opcao invalida!! Favor digitar novamente!");
        }
    }
}

contaBancaria dadosCliente () {
    contaBancaria nova; 
    printf ("\ndigite o nome do titular: ");
    scanf ("%s", nova.titular);
    setbuf(stdin, NULL);
    printf ("digite o numero da conta: ");
    scanf ("%d", &nova.numeroConta);
    setbuf(stdin, NULL);
    return nova;
}

double quantia () {
    double valor = 0;
    while (valor <= 0) {
        printf ("\ndigite um valor valido para a operacao: ");
        scanf ("%.2lf", &valor);
    } 
    return valor;
}
