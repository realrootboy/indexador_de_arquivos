#ifndef ARVTRIE_H
#define ARVTRIE_H

#define R_WAY 26

#include "Lista.h"

/* Definição da Estrutura de Arvore Trie */

struct arvtrie{
    char letra;
    L_int *indices;
    struct arvtrie* filho[R_WAY];
};

typedef struct arvtrie* ArvTrie;

/* Definição das Funções da Arvore Trie */

// -- Cria uma Trie
ArvTrie* criaTrie();

// -- Libera uma Trie
void liberaTrie();

// -- Insere Uma Palavra Na Trie
void insereTrie(ArvTrie *tr, char *palavra, int indice);

// -- Imprime Uma Trie
void imprimeTrie(ArvTrie *tr);

#endif