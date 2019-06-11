#include <ctype.h>
#include <stdio.h>

#include "../headers/Arquivos.h"

FILE* abreArquivo(char *path){
    return fopen(path, "r");
}

void fechaArquivo(FILE* f){
    fclose(f);
}

int lePalavra(FILE *f, char *str, int BUFFER){
    int i = 0;
    char c;
    while ((c = fgetc( f )) != EOF) if(isalpha((int)c)||isdigit((int)c)) break;

    if (c != EOF) str[i++] = c;
    else return 0;
    
    while (i<BUFFER-1 && (c = fgetc(f))!= EOF && (isalpha((int)c)||isdigit((int)c)))
        str[i++] = c;
    
    str[i] = '\0';

    return ftell(f) - i;
}