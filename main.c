#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "headers/Arquivos.h"
#include "headers/Arv.h"
#include "headers/ArvAVL.h"
#include "headers/ArvTRIE.h"
#include "headers/No.h"
#include "headers/Lista.h"
#include "headers/TabelaHash.h"

#define BUFFER 64

int main(int argc, char* argv[]){

    /* --------------------------------------------------- */

    // -- RANDOMICO PADRÃO COM SEED 100
	srand(100);

    /* Verificação da quantidade dos parametros de entrada */
	if(argc < 3){
		printf("Falta de argumentos\n");
		return 0;
	}

    /* Variaveis auxiliares */
    int i = 0;
	char palavra[BUFFER];
	int _ftell = 0;
    int arqs = argc - 2;

    /* Variaveis de Calculo de Tempo */
    clock_t t = clock();
    double time_taken = 0; 
        // -- t = clock();
        // -- t = clock() - t;
        // -- double time_taken = ((double)t)/CLOCKS_PER_SEC;

    /* --------------------------------------------------- */

    /* Criação de vetor de arquivos */
	FILE* f[arqs];
    for( i = 0 ; i < arqs ; i++ ) f[i] = NULL;
    for( i = 0 ; i < arqs ; i++ ){
        f[i] = abreArquivo(argv[i + 2]);
        if( f[i] == NULL ) break; 
    }
        // -- TRATAMENTO DE ERRO PARA ARQUIVOS
    if( i < arqs ){
        printf("Arquivo %s não encontrado.\n", argv[i + 2]);
        for( i = 0 ; i < arqs ; i++ ) fechaArquivo(f[i]);
        return -1;
    }

    /* --------------------------------------------------- */

    /* Uso de Listas Encadeadas */
	if(0 == strcmp(argv[1], "lista")){
		L_palavras *l[arqs];

        for( i = 0 ; i < arqs ; i++ ) l[i] = criaL_palavras();

        t = clock();

        for( i = 0 ; i < arqs ; i++ ){
           	t = clock();
	 
            while((_ftell = lePalavra(f[i], palavra, BUFFER)))
			    adicionaL_palavras(l[i], palavra, _ftell);

            t = clock() - t;
            time_taken = ((double) t) / CLOCKS_PER_SEC;

            printf("Insertion time of %s in list: %lf seconds\n", argv[i + 2], time_taken);
        }

		for( i = 0 ; i < arqs ; i++ ) destroiL_palavras(l[i]);

    /* Uso de Arvores de Busca Binária */
	} else if(0 == strcmp(argv[1], "arvore")){
		ArvBin *arv[arqs];

        for( i = 0 ; i < arqs ; i++ ) arv[i] = criarArvBin();

        for( i = 0 ; i < arqs ; i++ ){		
            t = clock();

            while((_ftell = lePalavra(f[i], palavra, BUFFER)))
			    insereArvBin(arv[i], palavra, _ftell);
            
		    t = clock() - t;
            time_taken = ((double) t) / CLOCKS_PER_SEC;
            printf("Insertion time of %s in binary tree: %lf seconds\n", argv[i + 2], time_taken);

        }
		for( i = 0 ; i < arqs ; i++ ) liberaArvBin(arv[i]);
    /* Uso de Arvores Balanceadas AVL */
	} else if(0 == strcmp(argv[1], "avl")){
		ArvAvl *arvavl[arqs];

        for( i = 0 ; i < arqs ; i++ ) arvavl[i] = criarArvAvl();

        for( i = 0 ; i < arqs ; i++ ){
		    t = clock();

            while((_ftell = lePalavra(f[i], palavra, BUFFER)))
			    insereArvAvl(arvavl[i], palavra, _ftell);
            
            t = clock() - t;
            time_taken = ((double) t) / CLOCKS_PER_SEC;
            printf("Insertion time of %s in balanced binary tree: %lf seconds\n", argv[i + 2], time_taken);

        }
		for( i = 0 ; i < arqs ; i++ ) liberaArvAvl(arvavl[i]);
    /* Uso de Arvores Trie */		
	} else if(0 == strcmp(argv[1], "trie")){
		ArvTrie *tr[arqs];

        for( i = 0 ; i < arqs ; i++ ) tr[i] = criaNoTrie();

        for( i = 0 ; i < arqs ; i++ ){
		    t = clock();

            while((_ftell = lePalavra(f[i], palavra, BUFFER)))
			    insereTrie(&(tr[i]), palavra, _ftell);
            
            t = clock() - t;
            time_taken = ((double) t) / CLOCKS_PER_SEC;
            printf("Insertion time of %s in trie: %lf seconds\n", argv[i + 2], time_taken);

        }
		for( i = 0 ; i < arqs ; i++ )liberaTrie(&(tr[i]));
    /* Uso de Tabelas Hash */
	} else if(0 == strcmp(argv[1], "hash")){
		Hash *h[arqs];
        
        for( i = 0 ; i < arqs ; i++ ) h[i] = criaHash(9999991);

        for( i = 0 ; i < arqs ; i++ ){
    		t = clock();

            while((_ftell = lePalavra(f[i], palavra, BUFFER)))
		    	insereHash(h[i], palavra, _ftell);
            
		    t = clock() - t;
            time_taken = ((double) t) / CLOCKS_PER_SEC;
            printf("Insertion time of %s in hash: %lf seconds\n", argv[i + 2], time_taken);

        }
		for( i = 0 ; i < arqs ; i++ ) liberaHash(h[i]);

        // -- TRATAMENTO DE ERRO PARA ESTRUTURA INVALIDA
	} else {
		printf("Tipo Invalido\n");
	}

    /* --------------------------------------------------- */

    /* Fechando corretamente os arquivos lidos */
    for( i = 0 ; i < arqs ; i++ ) fechaArquivo(f[i]);

	return 0;
}
