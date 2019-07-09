#!/bin/bash

.././indexador lista 5000 ../textos/10\ dracula.txt >> ../benchs/listaB.txt;
.././indexador arvore 5000 ../textos/10\ dracula.txt >> ../benchs/arvoreB.txt;
.././indexador avl 5000 ../textos/10\ dracula.txt >> ../benchs/avlB.txt;
.././indexador trie 5000 ../textos/10\ dracula.txt >> ../benchs/trieB.txt;
.././indexador hash 5000 ../textos/10\ dracula.txt >> ../benchs/hashB.txt;

.././indexador lista 10000 ../textos/10\ dracula.txt >> ../benchs/listaB.txt;
.././indexador arvore 10000 ../textos/10\ dracula.txt >> ../benchs/arvoreB.txt;
.././indexador avl 10000 ../textos/10\ dracula.txt >> ../benchs/avlB.txt;
.././indexador trie 10000 ../textos/10\ dracula.txt >> ../benchs/trieB.txt;
.././indexador hash 10000 ../textos/10\ dracula.txt >> ../benchs/hashB.txt;

.././indexador lista 15000 ../textos/10\ dracula.txt >> ../benchs/listaB.txt;
.././indexador arvore 15000 ../textos/10\ dracula.txt >> ../benchs/arvoreB.txt;
.././indexador avl 15000 ../textos/10\ dracula.txt >> ../benchs/avlB.txt;
.././indexador trie 15000 ../textos/10\ dracula.txt >> ../benchs/trieB.txt;
.././indexador hash 15000 ../textos/10\ dracula.txt >> ../benchs/hashB.txt;

.././indexador lista 20000 ../textos/10\ dracula.txt >> ../benchs/listaB.txt;
.././indexador arvore 20000 ../textos/10\ dracula.txt >> ../benchs/arvoreB.txt;
.././indexador avl 20000 ../textos/10\ dracula.txt >> ../benchs/avlB.txt;
.././indexador trie 20000 ../textos/10\ dracula.txt >> ../benchs/trieB.txt;
.././indexador hash 20000 ../textos/10\ dracula.txt >> ../benchs/hashB.txt;

.././indexador lista 25000 ../textos/10\ dracula.txt >> ../benchs/listaB.txt;
.././indexador arvore 25000 ../textos/10\ dracula.txt >> ../benchs/arvoreB.txt;
.././indexador avl 25000 ../textos/10\ dracula.txt >> ../benchs/avlB.txt;
.././indexador trie 25000 ../textos/10\ dracula.txt >> ../benchs/trieB.txt;
.././indexador hash 25000 ../textos/10\ dracula.txt >> ../benchs/hashB.txt;

