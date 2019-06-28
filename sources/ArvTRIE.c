#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../headers/ArvTRIE.h"

/* Definição das Funções da Arvore Trie */

// -- Cria uma Trie
ArvTrie* criaTrie(){
    ArvTrie *tr = (ArvTrie*) malloc(sizeof(ArvTrie));
        
    return tr;
}

// -- Libera uma Trie
void liberaTrie(ArvTrie* tr){
    if(tr == NULL) return;

    if(*tr == NULL) return;

    int i = 0;

    for( i = 0 ; i < R_WAY ; i++ )
        liberaTrie(&((*tr)->filho[i]));
    
    percorreL_int((*tr)->indices, liberaL_int_celula, 0);
    free((*tr)->indices);
    free(*tr);
}

// -- Insere Uma Palavra Na Trie
void insereTrie(ArvTrie *tr, char *palavra, int indice){
    if(tr == NULL) return;

    if(*tr == NULL) return;

   
}

// -- Imprime Uma Trie
void imprimeTrie(ArvTrie *tr){
    if(tr == NULL) return;

    if(*tr == NULL) return;

    int i = 0;

    printf("%c", (*tr)->letra);
    for( i = 0 ; i < R_WAY ; i++ ){
        imprimeTrie(&((*tr)->filho[i]));
        printf("\n");
    }
    
}