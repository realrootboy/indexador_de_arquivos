#ifndef LISTA_H
#define LISTA_H

#include "No.h"

/* Definição da Estrutura da Lista de Palavras */

struct l_palavras{
    struct no *dados;
    struct l_palavras *proximo;    
};

typedef struct l_palavras* L_palavras;

/* Definição das Funções da Lista de Palavras */

// -- Cria Uma Lista de Palavras
L_palavras* criaL_palavras();

// -- Percorre Uma Lista de Palavras Com Uma Função
void percorreL_palavras(L_palavras *l, void (*fnc)(L_palavras*));

// -- Libera Uma Celula de Lista de Palavras
void liberaL_palavras_celula(L_palavras *l);

// -- Destroi uma Lista de Palavras
void destroiL_palavras(L_palavras *l);

// -- Imprime Uma Celula de Lista de Palavras
void imprimeL_palavras_celula(L_palavras *l);

// -- Adiciona Uma Celula a Uma Lista de Palavras
void adicionaL_palavras(L_palavras *l, char *palavra, int indice);

/*======================================================*/

/* Definição da Estrutura de Lista de Inteiros */

struct l_int{
    int indice;
    struct l_int *proximo;
};

typedef struct l_int* L_int;

/* Definição das Funções da Lista de Inteiros */

// -- Cria Uma Lista de Inteiros
L_int* criaL_int();

// -- Percorre Uma Lista de Inteiros Com Uma Função
void percorreL_int(L_int *l, void (*fnc)(L_int*));

// -- Libera Uma Celula de Lista de Inteiros
void liberaL_int_celula(L_int *l);

// -- Imprime Uma Celula de Lista de Inteiros
void imprimeL_int_celula(L_int *l);

// -- Adiciona Uma Celula a Uma Lista de Inteiros
void adicionaL_int(L_int *l, int indice);

#endif