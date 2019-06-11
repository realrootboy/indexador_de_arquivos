#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/No.h"

// -- Cria um nó
No* criarNo(char *palavra, int indice){
    No *no = (No*) malloc(sizeof(No));

    if( no != NULL ){
        // -- Alocando Palavra
        no->palavra = (char*) malloc(sizeof(char) * (strlen(palavra) + 1));
        if(no->palavra != NULL) strcpy(no->palavra, palavra);
        else {
            free(no);
            return NULL;
        }
        
        // -- Alocando indices
        no->indices = criaL_int();
        
        if(no->indices == NULL){
            free(no->palavra);
            free(no);
            return NULL;
        }
        
        adicionaL_int(no->indices, indice);
    }
    return no;
}

// -- Libera um nó
void liberaNo(No *no){
    if( no == NULL ) return;
    if( no->palavra != NULL ) free(no->palavra);
    if( no->indices != NULL ) percorreL_int(no->indices, liberaL_int_celula);
    free(no->indices);
    free(no);
}

// -- Imprime o conteudo do nó
void imprimeNo(No *no){
    if( no == NULL ) return;
    if( no->palavra != NULL && no->indices != NULL ){
        printf("%s ", no->palavra);
        percorreL_int(no->indices, &imprimeL_int_celula);
        printf("\n");
    }
}