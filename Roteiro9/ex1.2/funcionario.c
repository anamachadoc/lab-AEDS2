#include"funcionario.h"

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

AVL* criaAVL(){
    AVL* raiz = (AVL*) malloc (sizeof(AVL));
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

void destroiAVL(AVL* raiz){
    if(raiz != NULL){
        destroiRec(*raiz);
        free(raiz);
    }
}

int estaVazia(AVL* raiz){
    if(raiz == NULL) return 0;
    return (*raiz == NULL);
}

//Calcula FB
int altura(NO* raiz){
    if(raiz == NULL) return 0;
    if(raiz->alt > 0)
        return raiz->alt;
    else{ 
        //printf("Calculando altura do (%d)..", raiz->info);
        return MAIOR(altura(raiz->esq), altura(raiz->dir)) + 1;
    }
}

int FB(NO* raiz){
    if(raiz == NULL) return 0;
    printf("\nCalculando FB do(a) %s", raiz->info.nome);
    return altura(raiz->esq) - altura(raiz->dir);
}

//Funcoes de Rotacao Simples
void avl_RotDir(NO** raiz){
   printf("\nRotacao Simples a DIREITA!");
   NO *aux;
   aux = (*raiz)->esq;
   (*raiz)->esq = aux->dir;
   aux->dir = *raiz;
   
   //Acertando alturas e FB
   //dos NOs afetados
    (*raiz)->alt = aux->alt = -1;
    aux->alt = altura(aux); 
    (*raiz)->alt = altura(*raiz); 
    aux->fb = FB(aux); 
    (*raiz)->fb = FB(*raiz);

   *raiz = aux;
}

void avl_RotEsq(NO** raiz){
   printf("\nRotacao Simples a ESQUERDA!");
   NO *aux;
   aux = (*raiz)->dir;
   (*raiz)->dir = aux->esq;
   aux->esq = *raiz;
   
   //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = aux->alt = -1;
    aux->alt = altura(aux); 
    (*raiz)->alt = altura(*raiz); 
    aux->fb = FB(aux); 
    (*raiz)->fb = FB(*raiz);
   
   *raiz = aux;
}

//Funcoes de Rotacao Dupla
void avl_RotEsqDir(NO** raiz){
    printf("\nRotacao Dupla ESQUERDA-DIREITA!");
    NO *fe; //filho esquerdo
    NO *ffd; //filho filho direito
    
    fe = (*raiz)->esq;
    ffd = fe->dir;
    
    fe->dir = ffd->esq;
    ffd->esq = fe;
    
    (*raiz)->esq = ffd->dir;
    ffd->dir = *raiz;

    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = fe->alt = ffd->alt = -1;
    fe->alt = altura(fe); 
    ffd->alt = altura(ffd);
    (*raiz)->alt = altura(*raiz); 
    fe->fb = FB(fe); 
    ffd->fb = FB(ffd);
    (*raiz)->fb = FB(*raiz);

    *raiz = ffd;
}

void avl_RotDirEsq(NO** raiz){
    printf("\nRotacao Dupla DIREITA-ESQUERDA!");
    NO* fd; //filho direito
    NO* ffe; //filho filho esquerdo

    fd = (*raiz)->dir;
    ffe = fd->esq;
    
    fd->esq = ffe->dir;
    ffe->dir = fd;
    
    (*raiz)->dir = ffe->esq;
    ffe->esq = *raiz;

    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = fd->alt = ffe->alt = -1;
    fd->alt = altura(fd); 
    ffe->alt = altura(ffe);
    (*raiz)->alt = altura(*raiz); 
    fd->fb = FB(fd);
    ffe->fb = FB(ffe);
    (*raiz)->fb = FB(*raiz);

    *raiz = ffe;
}

void avl_RotEsqDir2(NO** raiz){
    printf("\nRotacao Dupla 2 ESQUERDA-DIREITA!");
    avl_RotEsq(&(*raiz)->esq);
    avl_RotDir(raiz);
}

void avl_RotDirEsq2(NO** raiz){
    printf("\nRotacao Dupla 2 DIREITA-ESQUERDA!");
    avl_RotDir(&(*raiz)->dir);
    avl_RotEsq(raiz);
}


//Funcoes Auxiliares referentes a cada filho
void avl_AuxFE(NO **raiz){
   NO* fe;
   fe = (*raiz)->esq;
   if(fe->fb == +1) /* Sinais iguais e positivo*/
     avl_RotDir(raiz);
   else /* Sinais diferentes*/
     avl_RotEsqDir(raiz);
}

void avl_AuxFD(NO **raiz){
   NO* fd;
   fd = (*raiz)->dir;
   if(fd->fb == -1) /* Sinais iguais e negativos*/
     avl_RotEsq(raiz);
   else /* Sinais diferentes*/
     avl_RotDirEsq(raiz);
}

int insereRec(NO** raiz, Funcionario func){
    int ok; //Controle para as chamadas recursivas
    if(*raiz == NULL){
        NO* novo = alocarNO();
        if(novo == NULL) return 0;
        novo->info = func; novo->fb = 0, novo->alt = 1;
        novo->esq = NULL; novo->dir = NULL;
        *raiz = novo; return 1;
    }else{
        if((*raiz)->info.salario == func.salario){
            printf("\nFuncionario ja existente!"); ok = 0;
        }
        if(func.salario < (*raiz)->info.salario){
            ok = insereRec(&(*raiz)->esq, func);
            if(ok){
                switch((*raiz)->fb){
                    case -1:
                        (*raiz)->fb = 0; ok = 0; break;
                    case 0:
                        (*raiz)->fb = +1; 
                        (*raiz)->alt++; 
                        break;
                    case +1:
                        avl_AuxFE(raiz); ok = 0; break;
                }
            }
        }
        else if(func.salario > (*raiz)->info.salario){
            ok = insereRec(&(*raiz)->dir, func);
            if(ok){
                switch((*raiz)->fb){
                    case +1:
                        (*raiz)->fb = 0; ok = 0; break;
                    case 0:
                        (*raiz)->fb = -1; (*raiz)->alt++; break;
                    case -1:
                        avl_AuxFD(raiz); ok = 0; break;
                }
            }
        }
    }
    return ok;
}

int insereElem(AVL* raiz, Funcionario func){
    if(raiz == NULL) return 0;
    return insereRec(raiz, func);
}

int pesquisaRec(NO** raiz, Funcionario* func){
    if(*raiz == NULL) return 0;
    if((*raiz)->info.salario == func->salario) {
        strcpy (func->nome, (*raiz)->info.nome);
        func->anoContrato = (*raiz)->info.anoContrato;
        return 1;
    }
    if(func->salario < (*raiz)->info.salario) {
        return pesquisaRec(&(*raiz)->esq, func);
    } else {
        return pesquisaRec(&(*raiz)->dir, func);
    }
}

int pesquisa(AVL* raiz, Funcionario* func){
    if(raiz == NULL) return 0;
    if(estaVazia(raiz)) return 0;
    return pesquisaRec(raiz, func);
}

int removeRec(NO** raiz, Funcionario func){
    int ok, confere = 0;
    if(strcmp((*raiz)->info.nome, func.nome) == 0){
        confere = 1;
        NO* aux;
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            //Caso 1 - NO sem filhos
            printf("\nCaso 1: Liberando %s", (*raiz)->info.nome);
            liberarNO(*raiz);
            *raiz = NULL;
        }else if((*raiz)->esq == NULL){
            //Caso 2.1 - Possui apenas uma subarvore direita
            printf("\nCaso 2.1: Liberando %s", (*raiz)->info.nome);
            aux = *raiz;
            *raiz = (*raiz)->dir;
            liberarNO(aux);
        }else if((*raiz)->dir == NULL){
            //Caso 2.2 - Possui apenas uma subarvore esquerda
            printf("\nCaso 2.2: Liberando %s", (*raiz)->info.nome);
            aux = *raiz;
            *raiz = (*raiz)->esq;
            liberarNO(aux);
        }else{
            //Caso 3 - Possui as duas subarvores (esq e dir)
            //Duas estrategias:
            //3.1 - Substituir pelo NO com o MAIOR valor da subarvore esquerda
            //3.2 - Substituir pelo NO com o MENOR valor da subarvore direita
            printf("\nCaso 3: Liberando %s", (*raiz)->info.nome);
            //Estrategia 3.1:
            NO* Filho = (*raiz)->esq;
            while(Filho->dir != NULL)//Localiza o MAIOR valor da subarvore esquerda
                Filho = Filho->dir;
            (*raiz)->info = Filho->info;
            Filho->info = func;
            return removeRec(&(*raiz)->esq, func);
        }
        return 1;
    }else if(strcmp(func.nome, (*raiz)->info.nome) < 0){
        ok = removeRec(&(*raiz)->esq, func); 
        if(ok){
            switch((*raiz)->fb){
                case +1:
                case 0:
                    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
                    (*raiz)->alt = -1;
                    (*raiz)->alt = altura(*raiz); 
                    (*raiz)->fb = FB(*raiz);
                    break;
                case -1:
                    avl_AuxFD(raiz); break;
            }
        }
    }
    else if(strcmp(func.nome, (*raiz)->info.nome) > 0){ 
        ok = removeRec(&(*raiz)->dir, func);
        if(ok){
            switch((*raiz)->fb){
                case -1:
                case 0:
                    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
                    (*raiz)->alt = -1;
                    (*raiz)->alt = altura(*raiz); 
                    (*raiz)->fb = FB(*raiz);
                    break;
                case +1:
                    avl_AuxFE(raiz); break;
            }
        }
    }
    if (confere == 0) return 0; // elemento nao existe
    return ok;
}

int removeElem(AVL* raiz, Funcionario func){
    if(*raiz == NULL) return 0;
    return removeRec(raiz, func);
}

void em_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1);
        imprimeFunc (raiz->info);
        printf("[%d, %d, %d]", raiz->fb, nivel, raiz->alt);
        em_ordem(raiz->dir, nivel+1);
    }
}

void pre_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        imprimeFunc (raiz->info);
        printf("[%d, %d, %d]", raiz->fb, nivel, raiz->alt);
        pre_ordem(raiz->esq, nivel+1);
        pre_ordem(raiz->dir, nivel+1);
    }
}

void pos_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        pos_ordem(raiz->esq, nivel+1);
        pos_ordem(raiz->dir, nivel+1);
        imprimeFunc (raiz->info);
        printf("[%d, %d, %d]", raiz->fb, nivel, raiz->alt);
    }
}

void imprime(AVL* raiz){
    if(raiz == NULL) return;
    if(estaVazia(raiz)){
        printf("\nArvore Vazia!");
        return;
    }
    //printf("Em Ordem: [INFO, FB, NIVEL]"); 
    printf("\nEm Ordem: [INFO, FB, NIVEL, altura]"); 
    em_ordem(*raiz, 0);
    //printf("Pre Ordem: "); pre_ordem(*raiz, 0);
    //printf("Pos Ordem: "); pos_ordem(*raiz, 0);
    printf("\n");
}

void zerarNos (int* num) {
    *num = 0;
}

void numNos (NO* raiz, int* num) {
    if (raiz != NULL) {
        *num += 1;
        numNos (raiz->esq, num);
        numNos (raiz->dir, num);
    }
}

Funcionario infoFunc() {
    limpar ();
    Funcionario novo;
    printf ("\nDigite o nome do funcionario: ");
    fgets (novo.nome, 20, stdin);
    limpar ();
    printf ("Digite o salario: ");
    scanf ("%lf", &novo.salario);
    printf ("Digite o ano de contratacao: ");
    scanf ("%d", &novo.anoContrato);
    return novo;
}

void imprimeFunc (Funcionario func) {
    printf ("\nInformacoes do funcionario:\n");
    printf ("Nome: %s", func.nome); 
    printf ("Salario: %.2lf\n", func.salario);
    printf ("Ano de Contratacao: %d\n", func.anoContrato);
}

void limpar () {
    setbuf(stdin, NULL);
}

int maiorSalario (NO* raiz, Funcionario* func) {
    if (raiz->dir == NULL) {
        strcpy (func->nome, raiz->info.nome);
        func->salario = raiz->info.salario;
        func->anoContrato = raiz->info.anoContrato;
        return 1;
    }
    maiorSalario (raiz->dir, func);
}

int menorSalario (NO* raiz, Funcionario* func) {
    if (raiz->esq == NULL) {
        strcpy (func->nome, raiz->info.nome);
        func->salario = raiz->info.salario;
        func->anoContrato = raiz->info.anoContrato;
        return 1;
    }
    menorSalario (raiz->esq, func);
}