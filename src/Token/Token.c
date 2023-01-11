#include "../../include/Token/Token.h"


void SetNumToken(Token *token,int val)
{
   token->kind = TK_NUM;
   token->val = val;
}

void SetStrToken(Token *token,char *set_str)
{
    token->kind = TK_STR;
    token->str = ConsumeStr(&set_str);
}