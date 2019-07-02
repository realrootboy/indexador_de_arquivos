# Compiler
CC=gcc

# Flags for compiler
CC_FLAGS=-c         \
         -lm		\
		 -W         \
         -Wall      \
         -pedantic	\
		 -g


DEPS= headers/Arquivos.h headers/Arv.h headers/ArvAVL.h headers/ArvTRIE.h headers/Lista.h headers/No.h headers/TabelaHash.h 

OBJ= Arquivos.o Arv.o ArvAVL.o ArvTRIE.o Lista.o No.o TabelaHash.o 

EXEC= indexador

#
# Compilation and linking
#


main: main.c $(OBJ)
	$(CC) -o ${EXEC} $^ $(CFLAGS)
	rm -f *.o

%.o: sources/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)



clean:

