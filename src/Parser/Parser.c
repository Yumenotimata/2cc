#include "../../include/Parser/Parser.h"

Node *Parse(Token **token,Env **env)
{
    Node *node = NULL;

    while((*token)->kind != TK_EOF)
    {
        printf("no w token kind %s\n",token_kind[(*token)->kind]);
        switch((*token)->kind)
        {
            case TK_NUM:
                printf("is TK_NUM\n");
                node = expr(token,env,node);
                break;
            case TK_SYMBOL:
                if(isSameString((*token)->str,"("))
                {
                    printf("first (\n");
                    node = expr(token,env,NULL);
                    break;
                }
        }
        (*token) = (*token)->next;
    }

    printf("parse ended\n");
    return node;
}

