#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ex11.h"

void criarConta (contaBancaria* c, int numero, char *titular) {
   c->numeroConta = numero;
   strcpy (c->titular, titular);
   c->saldo = 0;
   printf ("conta %d criada!\n", c->numeroConta);
}

void depositar (contaBancaria *c, double valor) {
    if (valor > 0) {
        c->saldo += valor;
        printf ("deposito no valor de %lf foi realizado!\n", valor);
    } else {
        printf ("nao eh possivel realizar deposito de valor nao positivos!\n");
    }
}

void sacar (contaBancaria *c, double valor) {
    if (valor > 0) {
        if (c->saldo - valor < 0) {
        printf ("impossivel realizar um saque no valor de %lf, pois nao ha saldo suficiente!\n", valor);
        } else {
        c->saldo -= valor;
        printf ("saque no valor de %.2lf foi realizado!\n", valor);
        }
    } else {
        printf ("nao eh possivel sacar valores nao positivos!\n");
    }
    
}

double consultarSaldo (contaBancaria *c) {
    return c->saldo;
}

void imprimirInfo(contaBancaria *c) {
    printf ("\n informações da conta: \n");
    printf (" titular: %s numero da conta: %d\n saldo: %lf\n", c->titular, c->numeroConta, c->saldo);
}