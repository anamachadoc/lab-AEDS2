#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ex11.h"

void criarConta (contaBancaria* c, int numero, char *titular) {
    printf ("\n\n%s\n", titular);
   c->numeroConta = numero;
   strcpy (c->titular, titular);
   c->saldo = 0;
   printf ("conta %d criada!\n", c->numeroConta);
}

void depositar (contaBancaria *c, double valor) {
    c->saldo += valor;
    printf ("deposito no valor de %lf foi realizado!\n", valor);
}

void sacar (contaBancaria *c, double valor) {
    if (c->saldo - valor < 0) {
        printf ("impossivel realizar um saque no valor de %lf, pois nao ha saldo suficiente!\n", valor);
    } else {
        c->saldo -= valor;
        printf ("saque no valor de %.2lf foi realizado!\n", valor);
    }
}

double consultarSaldo (contaBancaria *c) {
    return c->saldo;
}

void imprimirInfo(contaBancaria *c) {
    printf ("\n informações da conta: \n");
    printf ("%s\n", c->titular);
    printf (" titular: %s\n numero da conta: %d\n saldo: %lf", c->titular, c->numeroConta, c->saldo);
}