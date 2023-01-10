#include "../include/compiler.h"

int main(int argc,char *argv[])
{
    FILE *fp;
    if(argv[1]!=NULL)
    {
        fp = fopen(argv[1],"r");
        printf("open %s\n",argv[1]);
    }else
    {
        fp = fopen("../in/code.c","r");
        printf("open default file\n");
    }
    if(fp == NULL)
    {
        printf("file open error\n");
        exit(1);
    }
    Token *token = tokenize(fp);
    
    return 0;
}