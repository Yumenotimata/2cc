VPATH = ../src:../src/Token:../include:../include/Token
CFLAGS = -g -c
main:main.o Token.o Tokenizer.o TokenizerTools.o
	gcc -g -o main main.o Token.o Tokenizer.o TokenizerTools.o

main.o:main.c 
	gcc $(CFLAGS) ../src/main.c

Token.o:Token.c Token.h
	gcc $(CFLAGS) ../src/Token/Token.c ../include/Token/Token.h

Tokenizer.o:Tokenizer.c Tokenizer.h
	gcc $(CFLAGS) ../src/Token/Tokenizer.c ../include/Token/Tokenizer.h

TokenizerTools.o:TokenizerTools.c TokenizerTools.h
	gcc $(CFLAGS) ../src/Token/TokenizerTools.c ../include/Token/TokenizerTools.h
