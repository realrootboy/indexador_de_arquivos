#ifndef LISTA_H
#define LISTA_H

/* Definição da Estrutura de Lista de Inteiros */

struct l_int{
    int indice;
    struct l_int *proximo;
};

typedef struct l_int L_int;

/* Definição das Funções da Lista de Inteiros */

L_int* criaL_int();

void percorreL_int(L_int *l, void (*fnc)(L_int*));

void liberaL_int_celula(L_int *l);

void imprimeL_int_celula(L_int *l);

void adicionaL_int(L_int *l, int indice);

#endif