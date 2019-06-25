#ifndef ARV_H
#define ARV_H

#include "No.h"

/* Definição da Estrutura de Arvore Binária */

struct arvbin{
    No *info;
    struct arvbin *l;
    struct arvbin *r;
};

typedef struct arvbin* ArvBin;

/* Definição das Funções da Arvore Binária */

// -- Cria Uma Arvore Binária
ArvBin* criarArvBin();

// -- Insere Um Nó Na Arvore Binária
void insereArvBin(ArvBin *arv, char *palavra, int indice);

// -- Libera Uma Arvore Binária
void liberaArvBin(ArvBin *arv);

// -- Libera Um Nó de Arvore Binária
void liberaNoArvBin(ArvBin *arv);

// -- Trata as Situações De Remoção 
ArvBin removeNoAtualArvBin(ArvBin atual);

// -- Remove Um Nó de Arvore Binária
void removeNoArvBin(ArvBin *arv, char *palavra);

// -- Imprime Um Nó de Arvore Binária
void imprimeNoArvBin(ArvBin *arv);

// -- Percorre Arvore Binária Pre-fixado
void percorreArvorePre(ArvBin *arv, void (*fnc)(ArvBin*));

// -- Percorre Arvore Binária Central
void percorreArvoreCen(ArvBin *arv, void (*fnc)(ArvBin*));

// -- Percorre Arvore Binária Pos-fixado
void percorreArvorePos(ArvBin *arv, void (*fnc)(ArvBin*));


#endif