#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/Lista.h"

// -- Cria Uma Lista de Palavras
L_palavras* criaL_palavras(){
    L_palavras *l = (L_palavras*) malloc(sizeof(L_palavras));

    if(l != NULL) (*l) = NULL;

    return l;
}

// -- Percorre Uma Lista de Palavras Com Uma Função
void percorreL_palavras(L_palavras *l, void (*fnc)(L_palavras*)){
    if( l == NULL ) return;
    if( *l == NULL ) return;

    fnc(l);

    percorreL_palavras(&((*l)->proximo), fnc);
}

// -- Libera Uma Celula de Lista de Palavras
void liberaL_palavras_celula(L_palavras *l){
    if( l == NULL ) return;
    if( *l == NULL ) return;

    liberaNo((*l)->dados);
}

// -- Destroi uma Lista de Palavras
void destroiL_palavras(L_palavras *l){
    if( l == NULL ) return;
    
    percorreL_palavras(l, liberaL_palavras_celula);

    free(l);
}

// -- Imprime Uma Celula de Lista de Palavras
void imprimeL_palavras_celula(L_palavras *l){
    if( l == NULL ) return;
    if( *l == NULL ) return;

    imprimeNo((*l)->dados);
}

// -- Adiciona Uma Celula a Uma Lista de Palavras
void adicionaL_palavras(L_palavras *l, char *palavra, int indice){
    if( l == NULL ) return;

    if( palavra == NULL ) return;
    if( indice == -1 ) return;

    struct l_palavras *novo = NULL;
    novo = (struct l_palavras*) malloc(sizeof(struct l_palavras));

    if(*l == NULL){
        if(novo != NULL){        
            novo->dados = criarNo(palavra, indice);
            if(novo->dados != NULL){
                novo->proximo = NULL;
                *l = novo;
            } else free(novo);
           return;
        }

        free(novo);
    }

}

/*======================================================*/

// -- Cria Uma Lista de Inteiros
L_int* criaL_int(){
    L_int *l = (L_int*) malloc(sizeof(L_int));

    if(l != NULL) (*l) = NULL;

    return l;
}

// -- Percorre Uma Lista de Inteiros Com Uma Função
void percorreL_int(L_int *l, void (*fnc)(L_int*)){
    if( l == NULL ) return;
    if( *l == NULL ) return;

    percorreL_int(&((*l)->proximo), fnc);

    fnc(l);
}

// -- Libera Uma Celula de Lista de Inteiros
void liberaL_int_celula(L_int *l){
    if( l == NULL ) return;
    if( *l == NULL ) return;
    
    free(*l);
}

// -- Imprime Uma Celula de Lista de Inteiros
void imprimeL_int_celula(L_int *l){
    if( l == NULL ) return;
    if( *l == NULL ) return;
    if( (*l)->proximo == NULL ) printf("%d\n", (*l)->indice);
    else printf("%d, ", (*l)->indice);
}

// -- Adiciona Uma Celula a Uma Lista de Inteiros
void adicionaL_int(L_int *l, int indice){
    if( l == NULL ) return;

    struct l_int *cel = (struct l_int*) malloc(sizeof(struct l_int));
    
    if( cel == NULL ) return;

    cel->indice = indice;
    cel->proximo = NULL;

    if( *l == NULL ){
        *l = cel;
    } else {
        struct l_int *aux = (*l)->proximo;
        while( aux->proximo != NULL ) aux = aux->proximo;
        aux->proximo = cel; 
    }
}