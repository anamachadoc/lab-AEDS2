#ifndef EX11_H
#define EX11_H

typedef struct {
    char titular[30];
    double saldo;
    int numeroConta;
} contaBancaria;

void criarConta (contaBancaria*, int, char*);
void depositar (contaBancaria*, double);
void sacar (contaBancaria*, double);
double consultarSaldo (contaBancaria*);
void imprimirInfo(contaBancaria *c);

#endif
