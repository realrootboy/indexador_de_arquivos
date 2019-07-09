#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../headers/ArvTRIE.h"

/* Definição das Funções da Arvore Trie */

// -- CRIA UM NÓ DE ARVORE TRIE
ArvTrie* criaNoTrie(){
    ArvTrie *tr = (ArvTrie*) malloc(sizeof(ArvTrie));
    
    int i = 0;
    
    if(tr != NULL){
        tr->isfolha = 0;
        tr->indices = NULL;
        for( i = 0 ; i < R_WAY ; i++ ) tr->filho[i] = NULL;
    }

    return tr;
}

// -- INSERE NUMA ARVORE TRIE
void insereTrie(ArvTrie **tr, char *palavra, int indice){
    if( tr == NULL ) return;

    ArvTrie *arv = *tr;

    char next;

    while(*palavra){
        next = *palavra - 'a';

        if(arv->filho[next] == NULL){
            arv->filho[next] = criaNoTrie();
        }

        arv = arv->filho[next];

        palavra++;
    }
    
    if(arv->indices == NULL) arv->indices = criaL_int();

    adicionaL_int(arv->indices, indice);

    arv->isfolha = 1;
}

// -- BUSCA UMA PALAVRA NA TRIE
L_int* buscaTrie(ArvTrie **tr, char *palavra){
    if( tr == NULL ) return NULL;

    ArvTrie *arv = *tr;

    while(*palavra){
        arv = arv->filho[*palavra - 'a'];
        if( arv == NULL ) return NULL;
        palavra++;
    }

    return arv->indices;
}

// -- RETORNA SE UM NÓ DA TRIE TEM FILHO
int temFilhoTrie(ArvTrie *tr){
    if( tr == NULL ) return -1;

    int i = 0;

    for( i = 0 ; i < R_WAY ; i++)
        if(tr->filho[i]) return 1;

    return 0;
}

// -- REMOVE UMA PALAVRA DA TRIE
void liberaTrie(ArvTrie **tr){
    if( tr == NULL ) return;
    if( *tr == NULL ) return;

    int i = 0;

    for( i = 0 ; i < R_WAY ; i++ ){
        liberaTrie(&((*tr)->filho[i]));
    }

    if((*tr)->isfolha) percorreL_int((*tr)->indices, liberaL_int_celula, 0);
    
    free((*tr)->indices);
    
    free(*tr);

}
