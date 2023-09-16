#ifndef EX12_H
#define EX12_H

typedef struct {
    char nome[30];
    double preco;
    int quant;
} Produto;

typedef struct {
    Produto *prodDisponivel; // array de produtos
    int quantProdutos;
} catalogoProdutos;

void criarCatalogo (catalogoProdutos *c);
void adicionarProduto (catalogoProdutos *c, char *nome, double preco, int quantidade);
int verificarEstoque (catalogoProdutos *c, char *nome);
void imprimirCatalogo (catalogoProdutos *c);

#endif