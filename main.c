#include <stdio.h>
#include <stdlib.h>

#include "headers/No.h"
#include "headers/Lista.h"
#include "headers/Arquivos.h"

#define BUFFER 64



int main(int argc, char* argv[]){
	L_palavras *l = criaL_palavras();

	int i = 1;

	char palavra[BUFFER];
	int _ftell = 0;

	FILE* f = abreArquivo("don_casmurro.txt");
	
	while((_ftell = lePalavra(f, palavra, BUFFER)))
		adicionaL_palavras(l, palavra, _ftell);
	
	
	percorreL_palavras(l, imprimeL_palavras_celula, 1);
	


	fechaArquivo(f);

	destroiL_palavras(l);

	return 0;
}
