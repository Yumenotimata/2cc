VPATH = ../src:../src/Token:../include:../include/Token:../src/Token:../src/Parser:../src/Parser/Node:../include/Parser:../include/Parser/Node:../src/Tools:../include/Tools
CFLAGS = -g -c

main:main.o Token.o Tokenizer.o TokenizerTools.o Node.o Parser.o ParserTools.o StringTool.o
	gcc -g -o main main.o Token.o Tokenizer.o TokenizerTools.o Node.o Parser.o ParserTools.o StringTool.o

main.o:main.c 
	gcc $(CFLAGS) ../src/main.c

Token.o:Token.c Token.h
	gcc $(CFLAGS) ../src/Token/Token.c ../include/Token/Token.h

Tokenizer.o:Tokenizer.c Tokenizer.h
	gcc $(CFLAGS) ../src/Token/Tokenizer.c ../include/Token/Tokenizer.h

TokenizerTools.o:TokenizerTools.c TokenizerTools.h
	gcc $(CFLAGS) ../src/Token/TokenizerTools.c ../include/Token/TokenizerTools.h

Node.o:Node.c Node.h
	gcc $(CFLAGS) ../src/Parser/Node/Node.c ../include/Parser/Node/Node.h

Parser.o:Parser.c Parser.h
	gcc $(CFLAGS) ../src/Parser/Parser.c ../include/Parser/Parser.h

ParserTools.o:ParserTools.c ParserTools.h
	gcc $(CFLAGS) ../src/Parser/ParserTools.c ../include/Parser/ParserTools.h

StringTool.o:StringTool.c StringTool.h
	gcc $(CFLAGS) ../src/Tools/StringTool.c ../include/Tools/StringTool.h




