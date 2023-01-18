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
            compile_file_str++;
            continue;
        }
        else if(isdigit(*compile_file_str))
        {
            SetNumToken(token,strtol(compile_file_str,&compile_file_str,10));
        }
        else if(ischar(*compile_file_str))
        {
            SetStrToken(token,&compile_file_str);
        }
        else if(issymbol(*compile_file_str))
        {
            SetSymToken(token,&compile_file_str);
        }
        else if(!memcmp(compile_file_str,";",1))
        {
            token->kind = TK_EOS;
            token->str = ";";
            compile_file_str++;
        }
        else
        {
            exit(1);
        }

        token->next = calloc(1,sizeof(Token));
        token = token->next;

    }

    token->kind = TK_EOF;
    token->next = NULL;
    token = h_token;

    return token;
}

