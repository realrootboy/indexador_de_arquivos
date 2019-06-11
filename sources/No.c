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
            free()
        }
    }

    return no;
}

// -- Libera um nó
void liberaNo(No *no);

// -- Imprime o conteudo do nó
void imprimeNo(No *no);