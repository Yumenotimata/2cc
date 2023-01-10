VPATH = ../src:../src/tools:../include:../include/tools

2cc:compiler.o tokenizer.o tokenizerTools.o token.o
	gcc -o 2cc compiler.o tokenizer.o tokenizerTools.o token.o

compiler.o:compiler.c compiler.h
	gcc -c ../src/compiler.c ../include/compiler.h

tokenizer.o:tokenizer.c compiler.h
	gcc -c ../src/tokenizer.c ../include/compiler.h

tokenizerTools.o:tokenizerTools.c tokenizerTools.h
	gcc -c ../src/tools/tokenizerTools.c ../include/tools/tokenizerTools.h

token.o:token.c token.h
	gcc -c ../src/token.c ../include/token.h