#include"LSE.h"

Lista* criaLista(){
    Lista *li;
    li = (Lista*) malloc (sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

int listaVazia(Lista *li){
    if(li == NULL) return 1;
    if(*li == NULL) return 1;//True - Vazia!
    return 0;//False - tem elemento!
}

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

int insereIni(Lista* li, int elem){
    if(li == NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->prox = *li;
    *li = novo;
    return 1;
}

int insereFim(Lista* li, int elem){
    if(li == NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->prox = NULL;
    if(listaVazia(li)){
        *li = novo;
    }else{
        NO* aux = *li;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return 1;
}

int removeIni(Lista* li){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    NO* aux = *li;
    *li = aux->prox;
    liberarNO(aux);
    return 1;
}

int removeFim(Lista* li){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    NO* ant, *aux = *li;
    while(aux->prox != NULL){
        ant = aux;
        aux = aux->prox;
    }
    if(aux == *li)
        *li = aux->prox;
    else  
        ant->prox = aux->prox;
    liberarNO(aux);
    return 1;
}

void imprimeLista(Lista* li){
    if(li == NULL) return;
    if(listaVazia(li)){
        printf("Lista Vazia!\n");
        return;
    }
    printf("Elementos:\n");
    NO* aux = *li;
    while(aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

void destroiLista(Lista* li){
    if(li != NULL){
        NO* aux;
        while((*li) != NULL){
            aux = *li;
            *li = (*li)->prox;
            liberarNO(aux);
        }
        free(li);
    }
}

int procura (Lista* li, int elem) {
    if(li == NULL) return -1;
    if(listaVazia(li)) return -1;
    int indice = 0;
    NO* aux = *li;
        while(aux->prox != NULL) {
            indice++;
            if (aux->info == elem) {
                return indice;
            }
            aux = aux->prox;
        }
        return -1;
}

void verifica (int indice) {
    if (indice == -1) {
        printf ("o elemento nao esta na lista!\n");
    } else {
        printf ("o elemento esta na posicao %d\n", indice);
    }
}

int tamanho (Lista* li) {
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    NO* aux = *li;
    int tam = 1;
    while (aux->prox != NULL) {
        tam++;
        aux = aux->prox;
    }
    return tam;
}

int insereOrdenada(Lista* li, int elem){
    if(li == NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->prox = NULL;
    if (listaVazia(li)) { // primeiro elemento
        *li = novo;
        return 1;
    } else { // ja tem elementos
        NO* aux = *li;
        if (aux->info > elem) {
            *li = novo;
            novo->prox = aux;
            return 1;
        } else {
            while (aux->prox != NULL) {
                if (aux->prox->info > elem) {
                    novo->info = elem;
                    novo->prox = aux->prox;
                    aux->prox = novo;
                    return 1;
                }
                aux = aux->prox;
            }
            aux->prox = novo;
            return 1;
        }
    }
}

