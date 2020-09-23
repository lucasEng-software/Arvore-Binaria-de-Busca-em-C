#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *pai;
    struct no *esq;
    struct no *dir;
}NO;

NO* raiz = NULL;

void in_ordem(NO* pt){
    if(pt->esq != NULL){
         in_ordem(pt->esq);
    }
    printf("%d,  ", pt->chave);
    //qualquer processamento! Ex: imprimindo
    if(pt->dir != NULL){
       in_ordem(pt->dir);
    }
}

void pre_ordem(NO* pt){
    printf("%d,  ", pt->chave);
    if(pt->esq != NULL){
         pre_ordem(pt->esq);
    }


    if(pt->dir != NULL){
       pre_ordem(pt->dir);
    }
}


void pos_ordem(NO* pt){
    if(pt->esq != NULL){
         pos_ordem(pt->esq);
    }


    if(pt->dir != NULL){
       pos_ordem(pt->dir);
    }
     printf("%d, ", pt->chave);
}



NO* busca_arvore (int x, NO* pt){
    if(pt == NULL){
        return NULL; //vazia :D
    }else if(x == pt->chave){
        return pt; // encontrei :D
    }else if(x < pt->chave){ //lado esq
        if(pt->esq == NULL){ //eu n posso
            return pt;
        }else{
            return busca_arvore(x, pt->esq);
        }
    }else { //lado dir
        if(pt->dir == NULL){ //eu n posso
            return pt;
        }else{
            return busca_arvore(x, pt->dir);
        }
    }
}

void insercao_arvore(int x){
    NO* pt = busca_arvore(x, raiz); // usa a busca para encontrar
                                // a posicao do no novo
    if(pt == NULL || pt->chave != x){
        NO* novo = (NO*) malloc (sizeof(NO));
        novo->chave = x;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->pai = pt;

        if(pt == NULL){ //vazia - raiz
            raiz = novo;
        }else if(x < pt->chave){ //elemento x <pt-> chave - esq
            pt->esq = novo;

        }else{                  //elemento x >pt-> chave - dir
            pt->dir = novo;

        }
    }else{
         printf("insercao invalida! :/");
    }
}



NO* remover( int chave){
    NO* pt = busca_arvore(chave, raiz);

    if(pt==NULL){
        return NULL;
    }else if(pt->esq==NULL && pt->dir==NULL){
        if(pt->chave > pt->pai->chave){
            pt->pai->dir = NULL;
        }else{
             pt->pai->esq = NULL;
        }
    }else if(pt->dir !=NULL && pt->esq == NULL){
        if(pt->chave > pt->pai->chave){
            pt->pai->dir = pt->dir;
        }else{
             pt->pai->esq = pt->dir;
        }

    }else if(pt->dir ==NULL && pt->esq != NULL){
          if(pt->chave > pt->pai->chave){
            pt->pai->dir = pt->esq;
        }else{
             pt->pai->esq = pt->esq;
        }
    }else{
        NO* aux = pt;
       while (aux->dir != NULL) {
          aux = aux->dir;
       }
        pt->chave = aux->chave;
        if(pt->dir->chave == pt->chave){
            pt->dir = NULL;
        }
        aux->pai->dir= NULL;
        if(aux ->esq != NULL){
            NO* aux2 = busca_arvore(aux->esq->chave, raiz);
            aux2->dir = aux->esq;
        }
    }

    return pt;

}



int main(){

    insercao_arvore(10);
    insercao_arvore(3);
    insercao_arvore(2);
    insercao_arvore(1);
    insercao_arvore(5);
    insercao_arvore(4);
    insercao_arvore(7);
    insercao_arvore(20);
    insercao_arvore(15);
    insercao_arvore(25);
    insercao_arvore(18);
    insercao_arvore(24);
    insercao_arvore(30);
    printf("\n in-order:");
    in_ordem(raiz);
    printf("\n pre-order:");
    pre_ordem(raiz);
    printf("\n pos-order:");
    pos_ordem(raiz);
    NO* aux = remover(20);
    printf("\n elemento removido: %d",aux->chave );
    //printf("dados da remoção: pai do removido %d e filho do removido %d",aux->pai->chave, aux->esq->chave);
    printf("\n pre-order:");
    pre_ordem(raiz);



    return 0;
}
