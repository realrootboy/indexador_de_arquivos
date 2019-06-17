#include <stdio.h>
#include <stdlib.h>



#include "headers/Arquivos.h"
#include "headers/Arv.h"
#include "headers/No.h"
#include "headers/Lista.h"

#define BUFFER 64

int main(int argc, char* argv[]){
	ArvBin* arv = criarArvBin();

	int i = 1;

	char palavra[BUFFER];
	int _ftell = 0;

	FILE* f = abreArquivo("don_casmurro.txt");
	
	while((_ftell = lePalavra(f, palavra, BUFFER)))
		insereArvBin(arv, palavra, _ftell);
	
	
	percorreArvorePre(arv, imprimeNoArvBin);
	
	liberaArvBin(arv);


	fechaArquivo(f);


	return 0;
}
