#include "../../include/Token/Token.h"


void SetNumToken(Token *token,int val)
{
   token->kind = TK_NUM;
   token->val = val;
}

void SetStrToken(Token *token,char **set_str)
{
    token->kind = TK_STR;
    token->str = ConsumeStr(set_str);
}

void SetSymToken(Token *token,char **set_symbol)
{
    token->kind = TK_SYMBOL;
    token->str = ConsumeSymbol(set_symbol);
}

void ShowToken(Token *token)
{
    if(token == NULL)
    {
        printf("returned");
        return;
    }

    if(!memcmp(token->kind,TK_NUM,strlen(token->kind)))
    {
        printf("token:%d\n",token->val);
    }
    else
    {
        printf("token:%s\n",token->str);
    }

    ShowToken(token->next);
}