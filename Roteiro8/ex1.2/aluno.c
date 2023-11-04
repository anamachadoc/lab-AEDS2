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

int removeRec(NO** raiz, Aluno al){
    if(*raiz == NULL) return 0;
    int comparacao = strcmp(al.nome, (*raiz)->info.nome);
    if(comparacao == 0){
        NO* aux;
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            //Caso 1 - NO sem filhos
            liberarNO(*raiz);
            *raiz = NULL;
        }else if((*raiz)->esq == NULL){
            //Caso 2.1 - Possui apenas uma subarvore direita
            aux = *raiz;
            *raiz = (*raiz)->dir;
            liberarNO(aux);
        }else if((*raiz)->dir == NULL){
            //Caso 2.2 - Possui apenas uma subarvore esquerda
            aux = *raiz;
            *raiz = (*raiz)->esq;
            liberarNO(aux);
        }else{
            //Caso 3 - Possui as duas subarvores (esq e dir)
            //Duas estrategias:
            //3.1 - Substituir pelo NO com o MAIOR valor da subarvore esquerda
            //3.2 - Substituir pelo NO com o MENOR valor da subarvore direita
            //Estrategia 3.1:
            NO* Filho = (*raiz)->esq;
            while(Filho->dir != NULL)//Localiza o MAIOR valor da subarvore esquerda
                Filho = Filho->dir;
            (*raiz)->info = Filho->info;
            Filho->info = al;
            return removeRec(&(*raiz)->esq, al);
        }
        return 1;
    }else if(comparacao < 0)
        return removeRec(&(*raiz)->esq, al);
    else 
        return removeRec(&(*raiz)->dir, al);
}

int removeElem(ABP* raiz, Aluno al){
    if(pesquisa(raiz, &al) == 0){
        printf("\nAluno inexistente!");
        return 0;
    }
    return removeRec(raiz, al);
}

void em_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1);
        imprimeAluno (raiz->info);
        printf ("nivel %d\n", nivel);
        em_ordem(raiz->dir, nivel+1);
    }
}

void maiorNota (NO* raiz, Aluno* al) {
    if (raiz != NULL) {
        if (raiz->info.nota > al->nota || al->nota == -1) {
            *al = raiz->info;
        }
        maiorNota (raiz->esq, al);
        maiorNota (raiz->dir, al);
    }
}

void menorNota (NO* raiz, Aluno* al) {
    if (raiz != NULL) {
        if (raiz->info.nota < al->nota || al->nota == -1) {
            *al = raiz->info;
        }
        menorNota (raiz->esq, al);
        menorNota (raiz->dir, al);
    }
}

Aluno infoAluno() {
    limpar ();
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
    printf ("Nota: %.2lf\n", al.nota);
}

void limpar () {
    fflush(stdin);
}

void reiniciarAluno (Aluno *al) {
    al->matricula = 0;
    al->nota = -1;
}




