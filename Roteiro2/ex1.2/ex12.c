#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ex12.h>

void criarCatalogo (catalogoProdutos *c) {
    c->quantProdutos = 0;
    printf ("\ncatalogo criado!");
}

void adicionarProduto (catalogoProdutos *c, char *nome, double preco, int quantidade) {
   if (c-> quantProdutos < 100) { // quantidade maxima de produtos permitida
       Produto adicionar;
       strcpy (adicionar.nome, nome);
       adicionar.preco = preco;
       adicionar.quant = quantidade;
       c->quantProdutos++;
       if (c->quantProdutos == 0) { // adicionando o primeiro produto
           c->prodDisponivel = (Produto*)malloc(sizeof(Produto));
           c->prodDisponivel[0] = adicionar;
       } else { // necessario realocar espaco
           c->prodDisponivel = realloc(c->prodDisponivel, c->quantProdutos * sizeof(Produto));
           c->prodDisponivel[(c->quantProdutos) - 1] = adicionar;
       }
   } else {
       printf ("\nnao eh possivel adiconar mais produtos, pois o catalogo ja esta completo!");
   }
}

int verificarEstoque (catalogoProdutos* c, char* nome) {
   for (int i = 0; i < c->quantProdutos; i++) {
       if (strcmp(nome, c->prodDisponivel[i].nome) == 0) { // eh o produto procurado
           return c->prodDisponivel[i].quant;
       }
   }
   return 0;
}

void imprimirCatalogo (catalogoProdutos* c) {
   if (c->quantProdutos != 0) {
       printf ("********************** CATALOGO ******************************");
       for (int i = 0; i < c->quantProdutos; i++) {
           printf ("\n PRODUTO %d: %s", i+1, c->prodDisponivel[i].nome);
           printf (" preco: R$ %lf\n quantidade disponivel: %d\n", c->prodDisponivel[i].preco, c->prodDisponivel[i].quant);
       }
       printf ("\n**************************************************************");
   } else {
       printf ("\nainda nao ha nenhum produto no catalogo!");
   }
}
