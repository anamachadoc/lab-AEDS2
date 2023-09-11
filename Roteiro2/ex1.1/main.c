#include"ex11.c"

int main () {
    contaBancaria* lista = (contaBancaria*)malloc(sizeof(contaBancaria));
    int tam; 
    if (!lista) {
        printf ("nao ha memoria disponivel!\n");
        exit(1);
    } else {
        inicializar(lista, &tam);
    }
    menu();
}