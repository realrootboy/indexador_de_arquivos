#ifndef ARVTRIE_H
#define ARVTRIE_H

struct arvtrie{
    char letra;
    struct arvtrie **filho;
};

typedef struct arvtrie* ArvTrie;

#endif