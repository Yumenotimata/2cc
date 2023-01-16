VPATH = ../src:../src/Token:../include:../include/Token:../src/Token:../src/Parser:../src/Parser/Node:../include/Parser:../include/Parser/Node:../src/Tools:../include/Tools:../src/Env:../include/Env:../src/Analyzer:../include/Analyzer:../src/Generator:../include/Generator:../out
CFLAGS = -g -c

main:main.o Token.o Tokenizer.o TokenizerTools.o Node.o Parser.o ParserTools.o StringTool.o Env.o Analyzer.o AnalyzerTools.o Generator.o GeneratorTools.o
	gcc -g -o main main.o Token.o Tokenizer.o TokenizerTools.o Node.o Parser.o ParserTools.o StringTool.o Env.o Analyzer.o AnalyzerTools.o Generator.o GeneratorTools.o

debug:main.o Token.o Tokenizer.o TokenizerTools.o Node.o Parser.o ParserTools.o StringTool.o Env.o Analyzer.o AnalyzerTools.o Generator.o GeneratorTools.o
	gcc -g -o main.out main.o Token.o Tokenizer.o TokenizerTools.o Node.o Parser.o ParserTools.o StringTool.o Env.o Analyzer.o AnalyzerTools.o Generator.o GeneratorTools.o

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

Env.o:Env.c Env.h
	gcc $(CFLAGS) ../src/Env/Env.c ../include/Env/Env.h

Analyzer.o:Analyzer.c Analyzer.h
	gcc $(CFLAGS) ../src/Analyzer/Analyzer.c ../include/Analyzer/Analyzer.h

AnalyzerTools.o:AnalyzerTools.c AnalyzerTools.h
	gcc $(CFLAGS) ../src/Analyzer/AnalyzerTools.c ../include/Analyzer/AnalyzerTools.h

Generator.o:Generator.c Generator.h
	gcc $(CFLAGS) ../src/Generator/Generator.c ../include/Generator/Generator.h

GeneratorTools.o:GeneratorTools.c GeneratorTools.h
	gcc $(CFLAGS) ../src/Generator/GeneratorTools.c ../include/Generator/GeneratorTools.h


run:
	nasm -g -f elf64 -o code.o ../out/code.asm 
	gcc -o code code.o


