#!/bin/bash

.././indexador lista ../textos/*.txt > ../benchs/lista.txt;
.././indexador arvore ../textos/*.txt > ../benchs/arvore.txt;
.././indexador avl ../textos/*.txt > ../benchs/avl.txt;
.././indexador trie ../textos/*.txt > ../benchs/trie.txt;
.././indexador hash ../textos/*.txt > ../benchs/hash.txt;
