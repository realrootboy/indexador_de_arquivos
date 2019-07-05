#ifndef TABELA_HASH
#define TABELA_HASH

#include "Lista.h"


/* Definição da Estrutura da Hash */

struct hash{
    int qnt;
    int pesos[64];
    int TABLE_SIZE;
    L_palavras **itens;
};

typedef struct hash Hash;

/* Definição das Funções Para Hash */


// -- Cria Uma Hash
Hash* criaHash(int size);

// -- Libera Uma Hash
void liberaHash(Hash *h);

// -- Função de Hashing
int hashingFunct(char *palavra, int *p);

// -- Inserção na Hashing
void insereHash(Hash *h, char *palavra, int indice);

// -- Busca na Hashing
L_int* buscaHash(Hash *h, char *palavra);

#endif