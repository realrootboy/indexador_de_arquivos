#ifndef ARQUIVOS_H
#define ARQUIVOS_H

/* Definição das Funções de Manipulação de Arquivos */

FILE* abreArquivo(char *path);

void fechaArquivo(FILE *f);

int lePalavra(FILE *f, char *str, int BUFFER);

#endif