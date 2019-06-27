#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "../headers/Arquivos.h"

int eValido(char c){
    switch(c){
        case '(':
        case ')':
        case '.':
        case ',':
        case '"':
        case '\'':
        case ' ':
        case '\n':
        case '?':
        case '!':
        case '[':
        case ']':
        case '-':
            return 0;
        default:
            return 1;
    }
}

FILE* abreArquivo(char *path){
    return fopen(path, "r");
}

void fechaArquivo(FILE* f){
    fclose(f);
}

int lePalavra(FILE *f, char *str, int BUFFER){
    int i = 0;
    int c;
    while ((c = fgetc( f )) != EOF) if(eValido(c) && isalpha(c)) break;

    if (c != EOF) str[i++] = tolower(c);
    else return 0;
    
    while (i<BUFFER-1 && ((c = (int) fgetc(f))!= EOF) && (eValido(c)) && isalpha(c)){
        str[i++] = tolower(c);
    }
    


    str[i] = '\0';

    return ftell(f) - strlen(str);
}