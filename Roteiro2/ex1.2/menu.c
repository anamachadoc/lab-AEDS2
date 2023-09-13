#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ex12.h"

void menuUsuario (catalogoProdutos* catalogo) {
    int opc = 0;
    Produto novo;
    while(opc != 6) {    
        printf ("\n======================== MENU ========================\n");
        printf (" 1. Criar catalogo\n 2. Adicionar produto\n 3. Verificar estoque\n 4. Imprimir catalogo\n 5. Encerrar\n\n");
        scanf ("%d", &opc);
        switch (opc) {
            case 1:
                criarCatalogo (catalogo);
                break;
            case 2:
                if (verifica(catalogo) != -1) {
                    novo = infoProduto ();
                    adicionarProduto (catalogo, novo.nome, novo.preco, novo.quant);
                }
                break;
            case 3:
                if (verifica(catalogo) != -1) {
                    sacar (conta, quantia());
                }
                break;
            case 4:
                if (verifica(catalogo) != -1) {
                    saldo = consultarSaldo (conta);
                    printf ("saldo da conta %d: %lf\n", conta->numeroConta, saldo);
                }
                break;
            case 5:
                free (catalogo);
                printf ("programa encerrado!\n");
                exit(1);
            default:
                printf ("Opcao invalida!! Favor digitar novamente!");
        }
    }
}

Produto infoProduto () {
    Produto novo;
    printf ("digite qual produto deseja adicionar: ");
    fgets (novo.nome, 30, stdin);
    setbuf(stdin, NULL);
    printf ("digite o preco de %s", novo.nome);
    scanf ("%lf", novo.preco);
    setbuf(stdin, NULL);
    printf ("digite a quantidade de %s", novo.quant);
    scanf ("%d", novo.quant);
    setbuf(stdin, NULL);
    return novo;
}

double verifica (catalogoProdutos* c) {
    if (c->quantProduto == -1) {
        printf ("crie um catalogo antes de realizar as demais operacoes!\n");
    }
    return c->quantProduto;
}