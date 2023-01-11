VPATH = ../src:../src/Token:../include:../include/Token

main:main.o Token.o Tokenizer.o TokenizerTools.o
	gcc -o main main.o Token.o Tokenizer.o TokenizerTools.o

main.o:main.c 
	gcc -c ../src/main.c

Token.o:Token.c Token.h
	gcc -c ../src/Token/Token.c ../include/Token/Token.h

Tokenizer.o:Tokenizer.c Tokenizer.h
	gcc -c ../src/Token/Tokenizer.c ../include/Token/Tokenizer.h

TokenizerTools.o:TokenizerTools.c TokenizerTools.h
	gcc -c ../src/Token/TokenizerTools.c ../include/Token/TokenizerTools.h
