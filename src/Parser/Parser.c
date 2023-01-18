#include "../../include/Parser/Parser.h"

Node *Parse(Token **token,Env **env,Node *cur_node)
{
    Node *node = NULL;

    while((*token)->kind != TK_EOF)
    {
        switch((*token)->kind)
        {   
            case TK_STR:
                node = parseStr(token,env,node);
                break;
            case TK_NUM:
                node = expr(token,env,node);
                break;
            case TK_SYMBOL:
                if(isSameString((*token)->str,"("))
                {
                    node = expr(token,env,NULL);
                    break;
                }
                if(isSameString((*token)->str,"}"))
                {
                    addaptNode(node,cur_node);
                    return node;
                }
                break;
        }
        if((*token) == NULL)
        {
            break;
        }
    }
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