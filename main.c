#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/Arquivos.h"
#include "headers/Arv.h"
#include "headers/ArvAVL.h"
#include "headers/ArvTRIE.h"
#include "headers/No.h"
#include "headers/Lista.h"

#define BUFFER 64

int main(int argc, char* argv[]){
	if(argc < 2){
		printf("Falta de argumentos\n");
		return 0;
	}

	char palavra[BUFFER];
	int _ftell = 0;

	FILE* f = abreArquivo("textos/frase_amor.txt");


	if(0 == strcmp(argv[1], "lista")){
		L_palavras *l = criaL_palavras();

		while((_ftell = lePalavra(f, palavra, BUFFER)))
			adicionaL_palavras(l, palavra, _ftell);

		percorreL_palavras(l, imprimeL_palavras_celula, 1);

		destroiL_palavras(l);
	} else if(0 == strcmp(argv[1], "arvore")){
		ArvBin *arv = criarArvBin();

		while((_ftell = lePalavra(f, palavra, BUFFER)))
			insereArvBin(arv, palavra, _ftell);
		
		percorreArvoreCen(arv, imprimeNoArvBin);
		liberaArvBin(arv);
	} else if(0 == strcmp(argv[1], "arvore_balanceada")){
		ArvAvl *arvavl = criarArvAvl();

		while((_ftell = lePalavra(f, palavra, BUFFER)))
			insereArvAvl(arvavl, palavra, _ftell);

		percorreArvoreAvlCen(arvavl, imprimeNoArvAvl);
		liberaArvAvl(arvavl);		
	} else if(0 == strcmp(argv[1], "trie")){
		ArvTrie *tr = criaTrie();

		while((_ftell = lePalavra(f, palavra, BUFFER)))
			insereTrie(tr, palavra, _ftell);

		//imprimeTrie(tr);
		liberaTrie(tr);
	} else if(0 == strcmp(argv[1], "hash")){

	} else {
		printf("Tipo Invalido\n");
	}

	fechaArquivo(f);

	return 0;
}
