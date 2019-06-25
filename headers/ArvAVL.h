#ifndef ARVAVL_H
#define ARVAVL_H

#include "Arv.h"

struct arvavl{
    No *info;
    int alt;
    struct arvavl *l;
    struct arvavl *r;
};

typedef struct arvavl* ArvAvl;

// -- Cria Uma Arvore Binária AVL
ArvAvl* criarArvAvl();

// -- Insere Um Nó Na Arvore Binária AVL
int insereArvAvl(ArvAvl *arv, char *palavra, int indice);

// -- Libera Uma Arvore Binária AVL
void liberaArvAvl(ArvAvl *arv);

// -- Libera Um Nó de Arvore Binária AVL
void liberaNoArvAvl(ArvAvl *arv);

// -- Remove Um Nó de Arvore Binária AVL
int removeNoArvAvl(ArvAvl *arv, char *palavra);

// -- Imprime Um Nó de Arvore Binária AVL
void imprimeNoArvAvl(ArvAvl *arv);

// -- Percorre Arvore AVL Pre-fixado
void percorreArvoreAvlPre(ArvAvl *arv, void (*fnc)(ArvAvl*));

// -- Percorre Arvore AVL Central
void percorreArvoreAvlCen(ArvAvl *arv, void (*fnc)(ArvAvl*));

// -- Percorre Arvore AVL Pos-fixado
void percorreArvoreAvlPos(ArvAvl *arv, void (*fnc)(ArvAvl*));

// -- Altura da Arvore AVL
int alturaArvoreAvl(ArvAvl *arv);

// -- Fator de Balanceamento Arvore AVL
int fatorDeBalanceamentoArvoreAvl(ArvAvl *arv);

// -- Rotação a Direita Arvore AVL
void rotDirArvAvl(ArvAvl *arv);

// -- Rotação a Esquerda Arvore AVL
void rotEsqArvAvl(ArvAvl *arv);

// -- Rotação Esquerda-Direita LR
void rotEsqDirLR(ArvAvl *arv);

// -- Rotação Direita-Esquerda RL
void rotDirEsqRL(ArvAvl *arv);

#endif