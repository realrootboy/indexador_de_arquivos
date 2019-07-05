#ifndef ARVTRIE_H
#define ARVTRIE_H

#define R_WAY 26

#include "Lista.h"

/* Definição da Estrutura da Arvore Trie */

struct arvtrie{
    int isfolha;
    L_int *indices;
    struct arvtrie *filho[R_WAY];
};

typedef struct arvtrie ArvTrie;

/* Definição das Funções da Arvore Trie */

// -- CRIA UM NÓ DE ARVORE TRIE
ArvTrie* criaNoTrie();

// -- INSERE NUMA ARVORE TRIE
void insereTrie(ArvTrie **tr, char *palavra, int indice);

// -- BUSCA UMA PALAVRA NA TRIE
L_int* buscaTrie(ArvTrie **tr, char *palavra);

// -- RETORNA SE UM NÓ DA TRIE TEM FILHO
int temFilhoTrie(ArvTrie *tr);

// -- REMOVE UMA PALAVRA DA TRIE
void liberaTrie(ArvTrie **tr);



#endif