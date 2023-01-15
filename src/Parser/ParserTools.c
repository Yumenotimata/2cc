#include "../../include/Parser/ParserTools.h"

Node *expr(Token **cur_token,Env **cur_env,Node *cur_node)
{
    Node *node = mul(cur_token,cur_env,cur_node);

    while((*cur_token)->kind == TK_SYMBOL)
    {
        if(match(cur_token,"+"))
        {
            printf("+ was parsed\n");
            Node *rhs = mul(cur_token,cur_env,cur_node);
            node = createNode(node,rhs,ND_ADD);
            printf("\n%s\n\n",node_kind[node->kind]);
            continue;
        }
        if(match(cur_token,"-"))
        {
            printf("/ was parsed\n");
            Node *rhs = mul(cur_token,cur_env,cur_node);
            node = createNode(node,rhs,ND_SUB);
            continue;
        }

        break;
    }
    
    Node *h_node = calloc(1,sizeof(Node));
    h_node->kind = ND_CALC;
    h_node->lhs = node;
    h_node->rhs = NULL;
    while(node->lhs != NULL)
    {
        node = node->lhs;
    }

    node->lhs  = cur_node;
    return h_node;
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
            printf("\n %s\n\n",node_kind[node->kind]);
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
            break;
        case TK_SYMBOL:
            if(match(cur_token,"(")) 
            {
                printf("mathc (\n");
                node = expr(cur_token,cur_env,NULL);
                match(cur_token,")");
                printf("match )\n");
                break;
            }

            break;
    }

    printf("parse return\n");
    return node;
}

Node *parseStr(Token **cur_token,Env **cur_env,Node *cur_node)
{
    Node *node = NULL;
    printf("parseStr\n");
    if((node = isInitializetion(cur_token,cur_env,cur_node))!=NULL)
    {
        printf("return parse Str\n");
        return node;
    }
}

Node *isInitializetion(Token **cur_token,Env **cur_env,Node *cur_node)
{
    Node *node = calloc(1,sizeof(Node));
    node->kind = ND_INIT;
    printf("isInitializetion\n");
    if(match(cur_token,"int"))
    {
        node->lhs = isDeclaration(cur_token,cur_env,cur_node,INT);    
    }
    else if(match(cur_token,"char"))
    {
        node->lhs =  isDeclaration(cur_token,cur_env,cur_node,CHAR);
    }
    else 
    {
        return NULL;
    }

    if(match(cur_token,"="))
    {   
        node->rhs = expr(cur_token,cur_env,NULL);
        match(cur_token,";");
        return node;
    }
    else if(match(cur_token,";"))
    {
        node->rhs = NULL;
        return node;
    }

    printf("Initializetion Error\n");
    exit(1);

}

Node *isDeclaration(Token **cur_token,Env **cur_env,Node *cur_node,TypeKind kind)
{
    Node *node = NULL;

    if(match(cur_token,"*"))
    {
        char *variable_name = readStr(cur_token);
        node = createVariableNode(variable_name,kind,cur_env);
    }
    else
    {   
        printf("read str\n");
        char *variable_name = readStr(cur_token);
        node = createVariableNode(variable_name,kind,cur_env);
    }

    node->lhs = cur_node;
    node->rhs = NULL;

    return node;

}