#include "../../include/Parser/Parser.h"

Node *Parse(Token **token,Env **env)
{
    Node *node = NULL;

    while((*token)->kind != TK_EOF)
    {
        printf("no w token kind %s\n",token_kind[(*token)->kind]);
        switch((*token)->kind)
        {   
            case TK_STR:
                printf("is TK_STR\n");
                node = parseStr(token,env,node);
                printf("breakstr %s\n",node_kind[node->kind]);
                break;
            case TK_NUM:
                printf("is TK_NUM\n");
                node = expr(token,env,node);
                break;
            case TK_SYMBOL:
                printf("tk_symbol\n");
                if(isSameString((*token)->str,"("))
                {
                    printf("first (\n");
                    node = expr(token,env,NULL);
                    break;
                }
                break;
        }
        printf("nandemonai %s\n",token_kind[(*token)->kind]);
        //(*token) = (*token)->next;
        if((*token) == NULL)
        {
            break;
        }
    }

    printf("parse ended %p\n",node);
    return node;
}

