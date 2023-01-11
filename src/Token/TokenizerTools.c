#include "../../include/Token/TokenizerTools.h"

char *fp2str(FILE *compile_file)
{
    //ファイルポインタを一度読むと、なぜか再度読むことができないのでファイルのサイズがわからない
    //そしてこのようなクソになりました
    char *compile_file_str = calloc(MAX_FILE_CHAR_SIZE,sizeof(char));
    char *h_str = compile_file_str;

    char ch;
    while((ch = fgetc(compile_file)) != EOF)
    {
        *compile_file_str = ch;
        compile_file_str++;
    }
    *compile_file_str = '\0';

    return h_str;
}

char *ConsumeStr(char **str)
{
    char *read_str = calloc(MAX_STR_SIZE,sizeof(char));
    char *h_read_str = read_str;

    while(ischar(**str))
    {
        *read_str = **str;
        read_str++;
        *str++;
    }
    *read_str = '\0';

    return h_read_str;
}

bool ischar(char ch)
{
    printf("char is %c\n",ch);
    if('a'<= ch && 'z' >= ch)
    {
        return true;
    }
    else if('A'<= ch && 'Z' >= ch)
    {
        return true;
    }

    return false;
}

bool issymbol(char ch)
{
    const char symbol_s[] = 
    {
        '+',    '-',    '*',    '/',
        '(',    ')',    '{',    '}',
        ';'
    };

    printf("size is %ld\n",sizeof(symbol_s));
    exit(1);
}