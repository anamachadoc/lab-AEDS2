#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"menu.h"

void menuUsuario (catalogoProdutos* catalogo) {
    int opc = 0;
    Produto novo, aux;
    while(opc != 6) {    
        setbuf (stdin, NULL);
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
                    if (verificarEstoque (catalogo, novo.nome) != 0) {
                       printf ("\nesse produto ja foi adicionado!");
                    } else {
                       adicionarProduto (catalogo, novo.nome, novo.preco, novo.quant);
                    }
                }
                break;
            case 3:
                if (verifica(catalogo) != -1) {
                   setbuf (stdin, NULL);
                   printf ("\ndigite o nome do produto que deseja: ");
                   fgets (aux.nome, 30, stdin);
                   aux.quant = verificarEstoque (catalogo, aux.nome);
                   if (aux.quant == 0) {
                       printf ("\nesse produto nao esta em estoque!");
                   } else {
                       printf ("\nha %d unidades de %s", aux.quant, aux.nome);
                   }
                }
                break;
            case 4:
                if (verifica(catalogo) != -1) {
                   imprimirCatalogo (catalogo);
                }
                break;
            case 5:
                free (catalogo);
                printf ("\nprograma encerrado!\n");
                exit(1);
            default:
                printf ("\nopcao invalida!! Favor digitar novamente!");
        }
    }
}

Produto infoProduto () {
    Produto novo;
    setbuf (stdin, NULL);
    printf ("\ndigite qual produto deseja adicionar: ");
    fgets (novo.nome, 30, stdin);
    setbuf (stdin, NULL);
    printf ("digite a quantidade: ");
    scanf ("%d", &(novo.quant));
    setbuf (stdin, NULL);
    printf ("digite o preco: ");
    scanf ("%lf", &(novo.preco));
    setbuf (stdin, NULL);
    return novo;
}

double verifica (catalogoProdutos* c) {
    if (c->quantProdutos == -1) {
        printf ("\ncrie um catalogo antes de realizar as demais operacoes!");
    }
    return c->quantProdutos;
}