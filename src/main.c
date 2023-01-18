#include "../include/Token/Tokenizer.h"
#include "../include/Parser/Parser.h"
#include "../include/Parser/Node/Node.h"
#include "../include/Env/Env.h"
#include "../include/Generator/Generator.h"
#include "../include/Analyzer/Analyzer.h"
#include <stdio.h>
#include <stdlib.h>

FILE *out_fp = NULL;

int main(int argc,char *argv[])
{
    FILE *compile_file;
    if(argc>1)
    {
        compile_file = fopen(argv[1],"r");
        printf("open %s\n",argv[1]);
    }
    else
    {
        compile_file = fopen("../in/code.c","r");
        printf("open default file\n");
    }
    if(compile_file == NULL)
    {
        printf("can not open file\n");
        exit(1);
    }

    Token *token = Tokenize(compile_file);
    //ShowToken(token);

    Env *env = initEnv();

    Node *node = Parse(&token,&env,NULL);


    Analyze(&node,&env);


    GenerateFunction(node,&env);

    return 0;
}