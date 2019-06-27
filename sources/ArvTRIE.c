#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../headers/ArvTRIE.h"

/* Definição das Funções da Arvore Trie */

// -- Cria uma Trie
ArvTrie* criaTrie(){
    ArvTrie *tr = (ArvTrie*) malloc(sizeof(ArvTrie));

    if(tr != NULL) *tr = NULL;

    return tr;
}

// -- Libera uma Trie
void liberaTrie(){

}

// -- Insere Uma Palavra Na Trie
void insereTrie(ArvTrie *tr, char *palavra, int indice){
    if(tr == NULL) return;
    if(*tr == NULL){
        *tr = malloc(sizeof(ArvTrie));
        if(*tr == NULL) return;
        
        struct arvtrie* aux = *tr;
        
        (aux)->indices = criaL_int();
        adicionaL_int((aux)->indices, indice);
    }
}

// -- Imprime Uma Trie
void imprimeTrie(ArvTrie *tr){

}