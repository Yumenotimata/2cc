#include "../../include/Token/Token.h"


void SetNumToken(int val)
{
    //token->next = NULL;
    // printf("0\n");
    // token->kind = TK_NUM;
    // printf("1\n");
    // token->val = val;
    exit(1);
}

void SetStrToken(char *set_str)
{
    token->kind = TK_STR;
    token->str = ConsumeStr(&set_str);
}