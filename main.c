#include <stdio.h>
#include <stdlib.h>

#include "headers/No.h"
#include "headers/Lista.h"
#include "headers/Arquivos.h"

#define BUFFER 64

int main(void){
	L_palavras *l = criaL_palavras();

	char palavra[BUFFER];
	int _fseek = 0;

	FILE* f = abreArquivo("README.md");

	while((_fseek = lePalavra(f, palavra, BUFFER)));

	
	
	
	percorreL_palavras(l, imprimeL_palavras_celula);
	


	fechaArquivo(f);

	destroiL_palavras(l);

	return 0;
}
