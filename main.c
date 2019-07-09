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

void selecionaAleatorias(char **palavras, int len_a, FILE **arqs, int len_b){
    char palavra[BUFFER];
    
    int i = 0;
    int j = 0;
    
    for(;;)
        for( i = 0 ; i < len_b ; i++){
            if(lePalavra(arqs[i], palavra, BUFFER))
                if(rand() % 2){
                    palavras[j] = (char*) malloc(sizeof(char) * (strlen(palavra) + 1));
                    strcpy(palavras[j], palavra);
                    j++;
                }
            if( j == len_a ) return;
            if((rand() % 256) == 255) rewind(arqs[i]);
        }
    
}

void tutorialMessage(){
    printf("========================================\n\n");
    printf("Voce esta executando o programa de maneira indevida!\n\n");
    printf("Para executar o programa corretamente deve-se seguir os seguintes passos:\n\n\n");
    printf("Escreva:\n");
    printf("./indexador <estrutura> <buscas> <arquivos[...]>\n\n");
    printf("<estrutura> = Estrutura a ser escolhida: lista, arvore, avl, trie ou hash\n");
    printf("<buscas> = Numero de buscas para realizar aleatoriamente na estrutura escolhida\n");
    printf("<arquivos> = Nome de todos arquivos separados por espaço.\n\n");
    printf("i.e: ./indexador trie 10000 textos/montecarlo.txt\n\n");
    printf("========================================\n");
}

int main(int argc, char* argv[]){
    /* --------------------------------------------------- */

    // -- RANDOMICO PADRÃO COM SEED 100
	srand(100);

    /* Verificação da quantidade dos parametros de entrada */
	if(argc < 4 || (atoi(argv[2]) <= 0)){
		tutorialMessage();
		return 0;
	}
    printf("\n");
    printf("Buscando palavras aleatorias... ");

    /* Variaveis auxiliares */
    int i = 0;
    int j = 0;
    int words = atoi(argv[2]);
	char palavra[BUFFER];
    char **palavras = (char**) malloc(sizeof(char*) * words);
	int _ftell = 0;
    int arqs = argc - 3;

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
        f[i] = abreArquivo(argv[i + 3]);
        if( f[i] == NULL ) break; 
    }
        // -- TRATAMENTO DE ERRO PARA ARQUIVOS
    if( i < arqs ){
        printf("Arquivo %s não encontrado.\n", argv[i + 3]);
        for( i = 0 ; i < arqs ; i++ ) fechaArquivo(f[i]);
        return -1;
    }
    
    selecionaAleatorias(palavras, words, f, arqs);
    printf("Palavras aleatorias carregadas.\n\n");
    for( i = 0 ; i < arqs ; i++ ) rewind(f[i]);
    
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

            printf("Insertion time of %s in list: %lf seconds\n", argv[i + 3], time_taken);
        }
        
        L_int *a;
        for( i = 0 ; i < arqs ; i++ ){
            t = clock();
            for( j = 0 ; j < words ; j++ ){
                a = buscaL_palavras(l[i], palavras[j]);
                // percorreL_int(a, imprimeL_int_celula, 1);
            }
            t = clock() - t;
            time_taken = ((double) t) / CLOCKS_PER_SEC;
            printf("Search time of %d words in %s using list: %lf seconds\n", words, argv[i + 3], time_taken);
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
            printf("Insertion time of %s in binary tree: %lf seconds\n", argv[i + 3], time_taken);

        }
        L_int *a;
        for( i = 0 ; i < arqs ; i++ ){
            t = clock();
            for( j = 0 ; j < words ; j++){
                a = buscaArvBin(arv[i], "know");
                //percorreL_int(a, imprimeL_int_celula, 1);
            }
            t = clock() -t;
            time_taken = ((double) t) / CLOCKS_PER_SEC;
            printf("Search time of %d words in %s using binary tree: %lf seconds\n", words, argv[i + 3], time_taken);
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
            printf("Insertion time of %s in balanced binary tree: %lf seconds\n", argv[i + 3], time_taken);

        }
        L_int *a;
        for( i = 0 ; i < arqs ; i++ ){
            t = clock();
            for( j = 0 ; j < words ; j++){
                a = buscaArvAvl(arvavl[i], "know");
                //percorreL_int(a, imprimeL_int_celula, 1);
            }
            t = clock() -t;
            time_taken = ((double) t) / CLOCKS_PER_SEC;
            printf("Search time of %d words in %s using balanced bt: %lf seconds\n", words, argv[i + 3], time_taken);
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
            printf("Insertion time of %s in trie: %lf seconds\n", argv[i + 3], time_taken);

        }
        L_int *a;
        for( i = 0 ; i < arqs ; i++ ){
            t = clock();
            for( j = 0 ; j < words ; j++){
                a = buscaTrie(&tr[i], "know");
                //percorreL_int(a, imprimeL_int_celula, 1);
            }
            t = clock() -t;
            time_taken = ((double) t) / CLOCKS_PER_SEC;
            printf("Search time of %d words in %s using trie: %lf seconds\n", words, argv[i + 3], time_taken);
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
            printf("Insertion time of %s in hash: %lf seconds\n", argv[i + 3], time_taken);

        }
        L_int *a;
        for( i = 0 ; i < arqs ; i++ ){
            t = clock();
            for( j = 0 ; j < words ; j++){
                a = buscaHash(h[i], "know");
                //percorreL_int(a, imprimeL_int_celula, 1);
            }
            t = clock() -t;
            time_taken = ((double) t) / CLOCKS_PER_SEC;
            printf("Search time of %d words in %s using hash: %lf seconds\n", words, argv[i + 3], time_taken);
        }
		for( i = 0 ; i < arqs ; i++ ) liberaHash(h[i]);

        // -- TRATAMENTO DE ERRO PARA ESTRUTURA INVALIDA
	} else {
		printf("Tipo Invalido\n");
	}

    /* --------------------------------------------------- */

    /* Fechando corretamente os arquivos lidos */
    for( i = 0 ; i < arqs ; i++ ) fechaArquivo(f[i]);

    /* Liberando o vetor de palavras sorteadas */
    for( i = 0 ; i < atoi(argv[2]) ; i++ ) free(palavras[i]);
    free(palavras);

    printf("\n");
	return 0;
}
