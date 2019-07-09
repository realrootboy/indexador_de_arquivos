#!/bin/bash

.././indexador lista 10 ../textos/*.txt >> ../benchs/lista.txt;
.././indexador arvore 10 ../textos/*.txt >> ../benchs/arvore.txt;
.././indexador avl 10 ../textos/*.txt >> ../benchs/avl.txt;
.././indexador trie 10 ../textos/*.txt >> ../benchs/trie.txt;
.././indexador hash 10 ../textos/*.txt >> ../benchs/hash.txt;

.././indexador lista 100 ../textos/*.txt >> ../benchs/lista.txt;
.././indexador arvore 100 ../textos/*.txt >> ../benchs/arvore.txt;
.././indexador avl 100 ../textos/*.txt >> ../benchs/avl.txt;
.././indexador trie 100 ../textos/*.txt >> ../benchs/trie.txt;
.././indexador hash 100 ../textos/*.txt >> ../benchs/hash.txt;

.././indexador lista 10000 ../textos/*.txt >> ../benchs/lista.txt;
.././indexador arvore 10000 ../textos/*.txt >> ../benchs/arvore.txt;
.././indexador avl 10000 ../textos/*.txt >> ../benchs/avl.txt;
.././indexador trie 10000 ../textos/*.txt >> ../benchs/trie.txt;
.././indexador hash 10000 ../textos/*.txt >> ../benchs/hash.txt;

.././indexador lista 100000 ../textos/*.txt >> ../benchs/lista.txt;
.././indexador arvore 100000 ../textos/*.txt >> ../benchs/arvore.txt;
.././indexador avl 100000 ../textos/*.txt >> ../benchs/avl.txt;
.././indexador trie 100000 ../textos/*.txt >> ../benchs/trie.txt;
.././indexador hash 100000 ../textos/*.txt >> ../benchs/hash.txt;

.././indexador lista 10000000 ../textos/*.txt >> ../benchs/lista.txt;
.././indexador arvore 10000000 ../textos/*.txt >> ../benchs/arvore.txt;
.././indexador avl 10000000 ../textos/*.txt >> ../benchs/avl.txt;
.././indexador trie 10000000 ../textos/*.txt >> ../benchs/trie.txt;
.././indexador hash 10000000 ../textos/*.txt >> ../benchs/hash.txt;

