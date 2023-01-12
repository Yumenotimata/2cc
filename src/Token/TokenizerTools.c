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
        //これかっこいるんだ
        (*str)++;
    }
    *read_str = '\0';

    return h_read_str;
}

char *ConsumeSymbol(char **str)
{
    char *symbol_s[] = 
    {
        "==",   "<=",   ">=",   "(",    ")",  
        "+",    "-",    "*",    "/",    "=",
        ";"
    };

    printf("*symbol_s size is %ld\n",(sizeof(symbol_s)/sizeof(*symbol_s)));
    for(int ar_ptr_i = 0;ar_ptr_i < (sizeof(symbol_s)/sizeof(*symbol_s));ar_ptr_i++)
    {
        printf("compare %s %s\n",*str,symbol_s[ar_ptr_i]);
        if(!memcmp((*str),symbol_s[ar_ptr_i],strlen((symbol_s[ar_ptr_i]))))
        {
            printf("%s is match to %s\n",(*str),symbol_s[ar_ptr_i]);
            (*str) += strlen(symbol_s[ar_ptr_i]);
            return symbol_s[ar_ptr_i];
        }
    }
    printf("unexpected symbol\n");
    exit(1);
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
        ';',    '='
    };

    printf("size is %ld\n",sizeof(symbol_s));
    for(int ar_i = 0;ar_i < sizeof(symbol_s);ar_i++)
    {
        if(symbol_s[ar_i] == ch)
        {
            printf("issymbol:return true\n");
            return true;
        }
    }
printf("issymbol:return false\n");
    return false;
}