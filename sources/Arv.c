#include "../headers/Arv.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -- Cria uma Arvore Binária
ArvBin* criarArvBin(){
    ArvBin* arv = (ArvBin*) malloc(sizeof(ArvBin));

    if( arv != NULL ) *arv = NULL;

    return arv;
}

// -- Insere Um Nó Na Arvore Binária
void insereArvBin(ArvBin *arv, char *palavra, int indice){
    if( arv == NULL ) return;
    if( palavra == NULL ) return;
    if( indice == -1 ) return;

    char cmp  = 0;

    if( *arv == NULL ){
        *arv = (ArvBin) malloc(sizeof(struct arvbin));
        (*arv)->info = criarNo(palavra, indice);
        (*arv)->l = NULL;
        (*arv)->r = NULL;
    } else {
        cmp = strcmp((*arv)->info->palavra, palavra);

        if( cmp < 0 ) insereArvBin(&((*arv)->l), palavra, indice);
        else if( !cmp ) adicionaL_int((*arv)->info->indices, indice);
        else insereArvBin(&((*arv)->r), palavra, indice);
        
    }
}

// -- Libera Uma Arvore Binária
void liberaArvBin(ArvBin *arv){
    if( arv == NULL ) return;

    percorreArvorePos(arv, liberaNoArvBin);
    free(arv);
}

// -- Libera Um Nó de Arvore Binária
void liberaNoArvBin(ArvBin *arv){
    if( arv == NULL ) return;
    if( *arv == NULL ) return;

    liberaNo((*arv)->info);

    free(*arv);
}

// -- Remove Um Nó de Arvore Binária
void removeNoArvBin(ArvBin *arv, char palavra){
    if( arv == NULL ) return;
    
    
}

// -- Imprime Um Nó de Arvore Binária
void imprimeNoArvBin(ArvBin *arv){
    if( arv == NULL ) return;
    if( *arv == NULL ) return;

    imprimeNo( (*arv)->info );
}

// -- Percorre Arvore Pre-fixado
void percorreArvorePre(ArvBin *arv, void (*fnc)(ArvBin*)){
    if( arv == NULL ) return;
    if( *arv == NULL ) return;

    fnc(arv);
    percorreArvorePre(&((*arv)->l), fnc);
    percorreArvorePre(&((*arv)->r), fnc);
}

// -- Percorre Arvore Central
void percorreArvoreCen(ArvBin *arv, void (*fnc)(ArvBin*)){
    if( arv == NULL ) return;
    if( *arv == NULL ) return;

    percorreArvoreCen(&((*arv)->l), fnc);
    fnc(arv);
    percorreArvoreCen(&((*arv)->r), fnc);
}

// -- Percorre Arvore Pos-fixado
void percorreArvorePos(ArvBin *arv, void (*fnc)(ArvBin*)){
    if( arv == NULL ) return;
    if( *arv == NULL ) return;

    percorreArvorePos(&((*arv)->l), fnc);
    percorreArvorePos(&((*arv)->r), fnc);
    fnc(arv);
}