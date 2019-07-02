#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/TabelaHash.h"

// -- Cria Uma Hash
Hash* criaHash(int size){
    if( size <= 0 ) return NULL;

    Hash *h = (Hash*) malloc(sizeof(Hash));
    
    int i = 0;

    if( h != NULL ){
        h->qnt = 0;
        h->col = 0;
        h->TABLE_SIZE = size;
        
        h->itens = (L_palavras**) malloc(sizeof(L_palavras*) * size);
        
        for( i = 0 ; i < 64 ; i++ ) h->pesos[i] = rand() % 100000;

        if(h->itens == NULL){
            free(h);
            return NULL;
        }

        for( i = 0 ; i < size ; i++ ) h->itens[i] = NULL;
    }

    return h;
}

// -- Libera Uma Hash
void liberaHash(Hash *h){
    if( h == NULL ) return;

    int i = 0;

    for( i = 0 ; i < h->TABLE_SIZE ; i++ ) destroiL_palavras(h->itens[i]);

    free(h->itens);
    free(h);
}

int powmeu(int a, int b){
    int i = 0;

    for( i = 0 ; i < b ; i++ ){
        a*=a;
    } 

    return a;
}

// -- Função de Hashing
int hashingFunct(char *palavra, int *p){
    int h = 7;
    int i = 0;

    for( i = 0 ; i < strlen(palavra) ; i++ ){
        h += p[i] * palavra[i];
    }


    return h;
}

// -- Inserção na Hashing
void insereHash(Hash *h, char *palavra, int indice){
    if( h == NULL ) return;

    int key = hashingFunct(palavra, h->pesos) % h->TABLE_SIZE;

    if(key >= h->TABLE_SIZE){
        return;
    }

    if( h->itens[key] == NULL ){ h->itens[key] = criaL_palavras(); }
    else{
        L_palavras *aux = h->itens[key];

        int flag = 1;

        while(*aux != NULL){
            if(0 == strcmp((*aux)->dados->palavra, palavra)){
                flag = 0;
                break;
            }
            aux = &((*aux)->proximo);
        }

        if(flag) h->col++;
    }

    h->qnt++;

    adicionaL_palavras(h->itens[key], palavra, indice);
}

// -- Busca na Hashing
//No* buscaHash(Hash *h, char *palavra){

//}

