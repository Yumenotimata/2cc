#include "../../include/Parser/ParserTools.h"

Node *expr(Token **cur_token,Env **cur_env,Node *cur_node)
{
    Node *node = mul(cur_token,cur_env,cur_node);

    while((*cur_token)->kind == TK_SYMBOL)
    {
        if(match(cur_token,"+"))
        {
            printf("+ was parsed\n");
            Node *rhs = primary(cur_token,cur_env,cur_node);
            node = createNode(node,rhs,ND_ADD);
            continue;
        }
        if(match(cur_token,"/"))
        {
            printf("/ was parsed\n");
            Node *rhs = primary(cur_token,cur_env,cur_node);
            node = createNode(node,rhs,ND_SUB);
            continue;
        }

        break;
    }

    Node *h_node = node;
    while(node->lhs != NULL)
    {
        node = node->lhs;
    }

    node->lhs  = cur_node;
    return h_node;

    return node;
}

Node *mul(Token **cur_token,Env **cur_env,Node *cur_node)
{
    Node *node = primary(cur_token,cur_env,cur_node);

    while((*cur_token)->kind == TK_SYMBOL)
    {
        if(match(cur_token,"*"))
        {
            printf("* was parsed\n");
            Node *rhs = primary(cur_token,cur_env,cur_node);
            node = createNode(node,rhs,ND_MUL);
            continue;
        }
        if(match(cur_token,"/"))
        {
            printf("/ was parsed\n");
            Node *rhs = primary(cur_token,cur_env,cur_node);
            node = createNode(node,rhs,ND_DIV);
            continue;
        }

        break;

    }

    return node;
}

Node *primary(Token **cur_token,Env **cur_env,Node *cur_node)
{
    Node *node = NULL;

    switch((*cur_token)->kind)
    {
        case TK_NUM:
            printf("cre num\n");
            node = createNumNode(readNum(cur_token));
    }

    return node;
}