#include "../../include/Token/Tokenizer.h"

Token *Tokenize(FILE *compile_file)
{
    Token *token = calloc(1,sizeof(Token));
    Token *h_token = token;

    char *compile_file_str = fp2str(compile_file);
    printf("%s\n",compile_file_str);

    while(*compile_file_str != '\0')
    {
        if(isspace(*compile_file_str))
        {
            printf("skip space\n");
            compile_file_str++;
            continue;
        }
        else if(isdigit(*compile_file_str))
        {
            SetNumToken(token,strtol(compile_file_str,&compile_file_str,10));
            printf("set num token\n");
        }
        else if(ischar(*compile_file_str))
        {
            printf("set str token\n");
            printf("now %s\n",compile_file_str);
            SetStrToken(token,&compile_file_str);
            printf("after %s\n",compile_file_str);
        }
        else if(issymbol(*compile_file_str))
        {
            printf("symbo %c\n",*compile_file_str);
            SetSymToken(token,&compile_file_str);
        }
        else
        {
            printf("unexpected token\n");
            exit(1);
        }
        printf("add token\n");
        token->next = calloc(1,sizeof(Token));
        token = token->next;

    }
    token->kind = TK_EOF;
    token->next = NULL;
    token = h_token;

    return token;
}

