#include<stdlib.h>
#include<stdio.h>
#include"ex11.h"
#include"menu.h"

int main () {
    contaBancaria* conta = (contaBancaria*)malloc(sizeof(contaBancaria));
    if (!conta) {
        printf ("nao ha memoria disponivel!\n");
        exit(1);
    } else {
        menuUsuario(conta);
    }
}