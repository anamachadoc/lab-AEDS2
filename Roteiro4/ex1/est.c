#include"est.h"

Lista* criaLista(){
    Lista* li;
    li = (Lista*) malloc (sizeof(Lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

void destroiLista(Lista *li){
    if(li != NULL)
        free(li);
}

int tamanhoLista(Lista *li){
    if(li == NULL)
        return -1;
    return li->qtd;
}

int listaCheia(Lista *li){
    if(li == NULL)
        return -1;
    return (li->qtd == MAX);
}

int listaVazia(Lista *li){
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}

int insereFim(Lista* li, int elem){
    if(li == NULL) return 0;
    if(!listaCheia(li)){
        li->dados[li->qtd] = elem;
        li->qtd++;
        return 1;
    }else{
        return 0;
    }
}

int insereIni(Lista* li, int elem){
    if(li == NULL) return 0;
    if(!listaCheia(li)){
        int i;
        for(i=li->qtd; i>0; i--){
            li->dados[i] = li->dados[i-1];
        }
        li->dados[0] = elem;
        li->qtd++;
        return 1;
    }else{
        return 0;
    }
}

int imprimeLista(Lista *li){
    if(li == NULL) return 0;
    int i;
    printf("Elementos:\n");
    for(i=0; i<li->qtd; i++){
        printf("%d ", li->dados[i]);
    }
    printf("\n");
    return 1;
}

int removeFim(Lista* li){
    if(li == NULL) return 0;
    if(!listaVazia(li)){
        li->qtd--;
        return 1;
    }else return 0;
}

int removeIni(Lista *li){
    if(li == NULL ) return 0;
    if(!listaVazia(li)){
        int i;
        for(i=0; i<li->qtd-1; i++)
            li->dados[i] = li->dados[i+1];
        li->qtd--;
        return 1;
    } else{
        return 0;
    }
}

int procura (Lista* li, int elem) {
    if (li != NULL && !listaVazia(li)) {
        for (int i = 0; i < li->qtd; i++) {
            if (li->dados[i] == elem) {
                return i;
            }
        }
    }
    return -1;
}

int verifica (int posicao) {
    if (posicao == -1) {
        printf ("o elemento nao esta na lista!\n");
    } else {
        printf ("o elemento esta na posicao %d do vetor da lista!\n", posicao);
    }
}

int insereOrdenada (Lista* li, int elem) {
    if (li != NULL && !listaCheia(li)) {
        if (li->qtd == 0) { // primeiro elemento
            li->dados[0] = elem;
            li->qtd++;
            return 1;
        } else { // demais elementos
            int posicao = 0;
            while (li->dados[posicao] < elem && posicao < li->qtd) {
                posicao++;
            }
            for (int i = li->qtd; i > posicao; i--) {
                li->dados[i] = li->dados[i-1];
            }
            li->dados[posicao] = elem;
            li->qtd++;
            return 1;
        }
    }
    return 0;
}

int remocao (Lista* li, int elem) {
    if (li != NULL && !listaVazia(li)) {
        int posicao = procura(li, elem);
        if (posicao != -1) {
            for (int i = posicao; i < li->qtd; i++) {
                li->dados[i] = li->dados[i+1];
            }
            li->qtd--;
            return 1;
        }
    }
    return 0;
}

int confereRemocao (int confere) {
    if (confere == 0) {
        printf ("o elemento nao pode ser removido, pois nao esta na lista!\n");
    } else {
        printf ("o elemento foi removido com sucesso!\n");
    }
}