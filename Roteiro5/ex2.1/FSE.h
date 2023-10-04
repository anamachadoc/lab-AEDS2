#ifndef FSE_H
#define FSE_H

typedef struct NO{
    int info ;
    struct NO* prox ;
} NO;

typedef struct {
    int qtd;
    struct NO* ini;
    struct NO* fim;
} Fila ;

Fila* criaFila ();
int filaVazia (Fila*);
int insere (Fila*, int);
int remove (Fila*);
int tamanho (Fila*);
int consultaElem (Fila*, int*);
void destroiFila (Fila*);

#endif
