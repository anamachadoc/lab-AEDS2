#include<stdlib.h>
#include<stdio.h>
#include"ex11.h"
#include"menu.h"

int main () {
    contaBancaria* conta = (contaBancaria*)malloc(sizeof(contaBancaria));
    conta->saldo = -1; // usado para conferir se uma conta ja foi adicionada
    menuUsuario(conta);
    return 0;
}