#include "../../include/Parser/Parser.h"

Node *Parse(Token **token,Env **env)
{
    Node *node = calloc(1,sizeof(Node));
    Node *h_node = node;

    while((*token)->kind != TK_EOF)
    {
        printf("%s\n",token_kind[(*token)->kind]);
        switch((*token)->kind)
        {
            case TK_NUM:
                printf("is TK_NUM\n");
                node = expr(token,env,node);
        }
        (*token) = (*token)->next;
    }

    printf("parse ended\n");
    return h_node;
}

