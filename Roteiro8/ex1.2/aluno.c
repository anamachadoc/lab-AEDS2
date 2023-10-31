#include"aluno.h"

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

ABP* criaABP(){
    ABP* raiz = (ABP*) malloc (sizeof(ABP));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void destroiRec(NO* no){
    if(no == NULL) return;
    destroiRec(no->esq);
    destroiRec(no->dir);
    liberarNO(no);
    no = NULL;
}

void destroiABP(ABP* raiz){
    if(raiz != NULL){
        destroiRec(*raiz);
        free(raiz);
    }
}

int estaVazia(ABP* raiz){
    if(raiz == NULL) return 0;
    return (*raiz == NULL);
}


int insereRec(NO** raiz, Aluno al){
    if(*raiz == NULL){
        NO* novo = alocarNO();
        if(novo == NULL) return 0;
        novo->info = al;
        novo->esq = NULL; novo->dir = NULL;
        *raiz = novo;
    }else{
        int comparacao = strcmp(al.nome, (*raiz)->info.nome);
        printf ("%d", comparacao);
        if(comparacao == 0){
            printf("\nAluno ja adicionado!"); 
            return 0;
        } else if(comparacao < 0) {
            return insereRec(&(*raiz)->esq, al);
        } else {
            return insereRec(&(*raiz)->dir, al);
        }
    }
    return 1;
}

int insereElem(ABP* raiz, Aluno al){
    if(raiz == NULL) return 0;
    return insereRec(raiz, al); // recursivo
}

int pesquisaRec(NO** raiz, Aluno* al){
    if(*raiz == NULL) return 0;
    if(strcmp((*raiz)->info.nome, al->nome) == 0) {
        al->nota = (*raiz)->info.nota;
        al->matricula = (*raiz)->info.matricula;
        return 1;
    }
    if(strcmp(al->nome, (*raiz)->info.nome) == -1)
        return pesquisaRec(&(*raiz)->esq, al);
    else if(strcmp(al->nome, (*raiz)->info.nome) == 1)
        return pesquisaRec(&(*raiz)->dir, al);
}


int pesquisa(ABP* raiz, Aluno* al){
    if(raiz == NULL) return 0;
    if(estaVazia(raiz)) return 0;
    return pesquisaRec(raiz, al);
}

NO* removeAtual(NO* atual){
    NO* no1, *no2;
    //Ambos casos no if(atual->esq == NULL)
    //Caso 1 - NO sem filhos
    //Caso 2.1 - Possui apenas uma subarvore direita
    if(atual->esq == NULL){
        no2 = atual->dir;
        liberarNO(atual);
        return no2;
    }
    //Caso 3 - Possui as duas subarvores (esq e dir)
    //Estrategia: 

    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    liberarNO(atual);
    return no2;
}

int removeIte(NO** raiz, Aluno al){
    if(*raiz == NULL) return 0;
    NO* atual = *raiz, *ant = NULL;
    while(atual != NULL){
        if(strcmp((*raiz)->info.nome, al.nome) == 0) {
            if(atual == *raiz)
                *raiz = removeAtual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = removeAtual(atual);
                else
                    ant->esq = removeAtual(atual);
            }
            return 1;
        }
        ant = atual;
        if(strcmp(al.nome, (*raiz)->info.nome) == -1)
            atual = atual->esq;
        else if (strcmp(al.nome, (*raiz)->info.nome) == 1)
            atual = atual->dir;
    }
    return 0;
}

int removeElem(ABP* raiz, Aluno al){
    if(pesquisa(raiz, &al) == 0){
        printf("\nAluno inexistente!");
        return 0;
    }
    return removeIte(raiz, al);
}

void em_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1);
        imprimeAluno (raiz->info);
        printf ("nivel %d\n", nivel);
        em_ordem(raiz->dir, nivel+1);
    }
}

Aluno infoAluno() {
    Aluno novo;
    printf ("\nDigite o nome do aluno: ");
    fgets (novo.nome, 20, stdin);
    limpar ();
    printf ("Digite a matricula: ");
    scanf ("%d", &novo.matricula);
    printf ("Digite a nota: ");
    scanf ("%lf", &novo.nota);
    return novo;
}

void imprimeAluno (Aluno al) {
    printf ("\nInformacoes do aluno:\n");
    printf ("Nome: %s", al.nome); 
    printf ("Matricula: %d\n", al.matricula);
    printf ("Nota: %lf\n", al.nota);
}

void limpar () {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n' && ch != '\0');
}




