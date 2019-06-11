#ifndef NO_H
#define NO_H

/* Definição da Estrutura de Nó */

struct no{
    char *palavra;
    int *indices;
    int quantidade;
};

typedef struct no No;

/* Definição das Funções do Nó */

// -- Cria um nó
No* criarNo(char *palavra, int indice);

// -- Libera um nó
void liberaNo(No *no);

// -- Imprime o conteudo do nó
void imprimeNo(No *no);

#endif