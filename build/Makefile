VPATH = ../src:../src/tools:../include:../include/tools

2cc:compiler.o tokenizer.o
	gcc -o 2cc compiler.o tokenizer.o

compiler.o:compiler.c compiler.h
	gcc -c ../src/compiler.c ../include/compiler.h

tokenizer.o:tokenizer.c compiler.h
	gcc -c ../src/tokenizer.c ../include/compiler.h