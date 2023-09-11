#ifndef EX11_H
#define EX11_H

typedef struct conta {
    conta *prox;
    char titular[30];
    float saldo;
    int numeroConta;
} contaBancaria;

void inicializar (contaBancaria*, int*);

#endif
