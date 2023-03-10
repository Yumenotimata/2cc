#include "../../include/Token/Token.h"

const char *token_kind[5] = 
{
    "TK_NUM","TK_STR","TK_EOF","TK_SYMBOL","TK_EOS"
};

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
        return;
    }

    printf("show %s\n",token_kind[token->kind]);
    switch(token->kind)
    {
        case TK_SYMBOL:
            printf("->tk symbol %s\n",token->str);
    }
    ShowToken(token->next);
}

bool match(Token **token,char *expect_str)
{
    if((*token) == NULL)
    {
        exit(1);
    }
    if(isSameString((*token)->str,expect_str))
    {
        printf("match %s\n",(*token)->str);
        (*token) = (*token)->next;
        return true;
    }
    
    return false;
}

bool expect(Token **token,char *expect_str)
{
     if((*token)->kind == TK_STR || (*token)->kind == TK_SYMBOL || (*token)->kind == TK_EOS)
    {
        if(isSameString((*token)->str,expect_str))
        {
            printf("expect match %s\n",(*token)->str);
            (*token) = (*token)->next;
            return true;
        }
    }
    exit(1);
}

bool isSameToken(Token **token,char *expect_str)
{
    if((*token)->kind == TK_STR || (*token)->kind == TK_SYMBOL  || (*token)->kind == TK_EOS)
    {
        if(isSameString((*token)->str,expect_str))
        {
            return true;
        }
        return false;
    }

    return false;
}

int readNum(Token **cur_token)
{
    int val_buf = (*cur_token)->val;
    (*cur_token) = (*cur_token)->next;

    return val_buf;
}

char *readStr(Token **cur_token)
{
    char *str = (*cur_token)->str;
    (*cur_token) = (*cur_token)->next;
    return str;
}