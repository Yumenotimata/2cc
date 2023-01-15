#include "../../include/Parser/Parser.h"

Node *Parse(Token **token,Env **env,Node *cur_node)
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
                if(isSameString((*token)->str,"}"))
                {
                    printf("}ended\n");
                    addaptNode(node,cur_node);
                    return node;
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

void addaptNode(Node *cur_node,Node *addapt_node)
{
    while(cur_node->lhs != NULL)
    {
        cur_node = cur_node->lhs;
    }

    cur_node->lhs = addapt_node;

}

void handleEndNode(Node **cur_node)
{
    if((*cur_node)->lhs == NULL || (*cur_node)->rhs == NULL)
    {
        return;
    }

    handleEndNode(&(*cur_node)->lhs);
    handleEndNode(&(*cur_node)->rhs);

    return;
}

void addContext(Node **cur_node,NodeKind kind)
{
    Node *context_node = createNode((*cur_node),NULL,kind);
    (*cur_node) = context_node; 
}