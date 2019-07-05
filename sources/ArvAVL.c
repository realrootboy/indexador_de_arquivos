#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/ArvAVL.h"

int maior(int x, int y){ return x > y ? x : y; }

// -- Cria Uma Arvore Binária AVL
ArvAvl* criarArvAvl(){
    ArvAvl* arv = (ArvAvl*) malloc(sizeof(ArvAvl));

    if( arv != NULL ) *arv = NULL;

    return arv;
}

// -- Insere Um Nó Na Arvore Binária AVL
int insereArvAvl(ArvAvl *arv, char *palavra, int indice){
    if( arv == NULL ) return 0;
    if( palavra == NULL ) return 0;
    if( indice == -1 ) return 0;

    char cmp  = 0;
    char ins = 0;

    if( *arv == NULL ){
        *arv = (ArvAvl) malloc(sizeof(struct arvavl));
        
        if((*arv) == NULL) return 0;

        (*arv)->info = criarNo(palavra, indice);
        (*arv)->alt = 0;
        (*arv)->l = NULL;
        (*arv)->r = NULL;

        return 1;
    } else {

        cmp = strcmp((*arv)->info->palavra, palavra);

        if( cmp < 0 ){
            if((ins = insereArvAvl(&((*arv)->l), palavra, indice)) == 1){
                if(fatorDeBalanceamentoArvoreAvl(arv) >= 2){
                    if(strcmp(((*arv)->l)->info->palavra, palavra) > 0){
                        rotDirArvAvl(arv);
                    } else {
                        rotEsqDirLR(arv);
                    }
                }
               
            }
        } else if( !cmp ){ 
            adicionaL_int((*arv)->info->indices, indice);
            return 0;
        }
        else{
            if((ins = insereArvAvl(&((*arv)->r), palavra, indice)) == 1){
                if(fatorDeBalanceamentoArvoreAvl(arv) >= 2){
                    if(strcmp(((*arv)->r)->info->palavra, palavra) < 0){ 
                        rotEsqArvAvl(arv);
                    } else {
                        rotDirEsqRL(arv);
                    }
                } 
            }
        }

        (*arv)->alt = 1 + maior(alturaArvoreAvl(&((*arv)->l)), alturaArvoreAvl(&((*arv)->r)));
        
        return (int) ins;
    }

    
}

// -- Busca um Nó Na Arvore Binária AVL e Retorna Seus Indices
L_int* buscaArvAvl(ArvAvl *arv, char *palavra){
    if( arv == NULL ) return NULL;
    if( *arv == NULL ) return NULL;
    
    char cmp = strcmp((*arv)->info->palavra, palavra);

    if( cmp < 0 ) buscaArvAvl(&((*arv)->l), palavra);
    else if( !cmp ) return (*arv)->info->indices;
    else buscaArvAvl(&((*arv)->r), palavra);
}

// -- Libera Uma Arvore Binária AVL
void liberaArvAvl(ArvAvl *arv){
    if( arv == NULL ) return;

    percorreArvoreAvlPos(arv, liberaNoArvAvl);
    free(arv);
}

// -- Libera Um Nó de Arvore Binária AVL
void liberaNoArvAvl(ArvAvl *arv){
    if( arv == NULL ) return;
    if( *arv == NULL ) return;

    liberaNo((*arv)->info);

    free(*arv);
}

// -- Remove Um Nó de Arvore Binária AVL
int removeNoArvAvl(ArvAvl *arv, char *palavra){
    
}

// -- Imprime Um Nó de Arvore Binária AVL
void imprimeNoArvAvl(ArvAvl *arv){
    if( arv == NULL ) return;
    if( *arv == NULL ) return;

    imprimeNo( (*arv)->info );
}

// -- Percorre Arvore AVL Pre-fixado
void percorreArvoreAvlPre(ArvAvl *arv, void (*fnc)(ArvAvl*)){
    if( arv == NULL ) return;
    if( *arv == NULL ) return;

    fnc(arv);
    percorreArvoreAvlPre(&((*arv)->l), fnc);
    percorreArvoreAvlPre(&((*arv)->r), fnc);
}

// -- Percorre Arvore AVL Central
void percorreArvoreAvlCen(ArvAvl *arv, void (*fnc)(ArvAvl*)){
    if( arv == NULL ) return;
    if( *arv == NULL ) return;

    percorreArvoreAvlCen(&((*arv)->l), fnc);
    printf("alt: %d - ", (*arv)->alt);    fnc(arv);
    percorreArvoreAvlCen(&((*arv)->r), fnc);
}

// -- Percorre Arvore AVL Pos-fixado
void percorreArvoreAvlPos(ArvAvl *arv, void (*fnc)(ArvAvl*)){
    if( arv == NULL ) return;
    if( *arv == NULL ) return;

    percorreArvoreAvlPos(&((*arv)->l), fnc);
    percorreArvoreAvlPos(&((*arv)->r), fnc);
    fnc(arv);
}

// -- Altura da Arvore AVL
int alturaArvoreAvl(ArvAvl *arv){
    if(arv == NULL) return -1;
    if(*arv == NULL) return -1;

    return (*arv)->alt;
}

// -- Fator de Balanceamento Arvore AVL
int fatorDeBalanceamentoArvoreAvl(ArvAvl *arv){
    return labs(alturaArvoreAvl(&((*arv)->l)) - alturaArvoreAvl(&((*arv)->r)));
}

// -- Rotação a Direita Arvore AVL
void rotDirArvAvl(ArvAvl *arv){ // ROTAÇÃO LL
    if(arv == NULL) return;
    if(*arv == NULL) return;
    if((*arv)->l == NULL) return;


    ArvAvl no = (*arv)->l;
    (*arv)->l = (no)->r;
    (no)->r = (*arv);

    (*arv)->alt = 1 + maior(alturaArvoreAvl(&((*arv)->l)), alturaArvoreAvl(&((*arv)->r))); 
    (no)->alt = 1 + maior(alturaArvoreAvl(&(no)->l), alturaArvoreAvl(&(no)->r));
    
    *arv = no;
}

// -- Rotação a Esquerda Arvore AVL
void rotEsqArvAvl(ArvAvl *arv){ // ROTAÇÃO RR
    if(arv == NULL) return;
    if(*arv == NULL) return;
    if((*arv)->r == NULL) return;

    ArvAvl no = (*arv)->r;
    (*arv)->r = (no)->l;
    (no)->l = (*arv);

    (*arv)->alt = 1 + maior(alturaArvoreAvl(&((*arv)->l)), alturaArvoreAvl(&((*arv)->r))); 
    (no)->alt = 1 + maior(alturaArvoreAvl(&((no)->l)), alturaArvoreAvl(&((no)->r)));

    *arv = no;
}

// -- Rotação Esquerda-Direita LR
void rotEsqDirLR(ArvAvl *arv){
    rotEsqArvAvl(&((*arv)->l));
    rotDirArvAvl(arv);
}

// -- Rotação Direita-Esquerda RL
void rotDirEsqRL(ArvAvl *arv){
    rotDirArvAvl(&((*arv)->r));
    rotEsqArvAvl(arv);
}