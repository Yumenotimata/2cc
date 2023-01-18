#include "../../include/Parser/ParserTools.h"

Node *expr(Token **cur_token,Env **cur_env,Node *cur_node)
{
    Node *node = mul(cur_token,cur_env,cur_node);

    while((*cur_token)->kind == TK_SYMBOL)
    {
        if(match(cur_token,"+"))
        {
            Node *rhs = mul(cur_token,cur_env,cur_node);
            node = createNode(node,rhs,ND_ADD);
            continue;
        }
        if(match(cur_token,"-"))
        {
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
            Node *rhs = primary(cur_token,cur_env,cur_node);
            node = createNode(node,rhs,ND_MUL);
            continue;
        }
        if(match(cur_token,"/"))
        {
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
            node = createNumNode(readNum(cur_token));
            break;
        case TK_SYMBOL:
            if(match(cur_token,"(")) 
            {
                node = expr(cur_token,cur_env,NULL);
                match(cur_token,")");
            }
            break;
        case TK_STR:
            node = createStrNode(readStr(cur_token));
            break;
    }

    return node;
}

Node *parseStr(Token **cur_token,Env **cur_env,Node *cur_node)
{
    Node *node = NULL;

    if((node = isDefination(cur_token,cur_env,cur_node)) != NULL)
    {
        return node;
    }
    if((node = isAssign(cur_token,cur_env,cur_node)) != NULL)
    {
        return node;
    }
    if((node = isReturn(cur_token,cur_env,cur_node)) != NULL)
    {
        return node;
    }
    if((node = ifStatement(cur_token,cur_env,cur_node)) != NULL)
    {
        return node;
    }
    if((node = isWhileStatement(cur_token,cur_env,cur_node)) != NULL)
    {
        return node;
    }


}

Node *isDefination(Token **cur_token,Env **cur_env,Node *cur_node)
{
    Node *node = calloc(1,sizeof(Node));

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
        free(node);
        return NULL;
    }


    if(match(cur_token,"="))
    {   
        node->kind = ND_INIT;
        node->rhs = expr(cur_token,cur_env,NULL);
        match(cur_token,";");
        return node;
    }
    else if(match(cur_token,";"))
    {
        node->kind = ND_INIT;
        node->rhs = NULL;
        return node;
    }
    else if(match(cur_token,"("))
    {   
        node = node->lhs;
        node->kind = ND_FUNC;
        Node *argument_node = NULL;
        while(!isSameToken(cur_token,")"))
        {
            argument_node = isArgumentNode(cur_token,cur_env,argument_node);
        }

        match(cur_token,")");
        match(cur_token,"{");
        Node *func_syntax_node = Parse(cur_token,cur_env,NULL);
        match(cur_token,"}");
        Node *first_node = createNode(argument_node,func_syntax_node,ND_NULL);
        node->rhs = first_node;
        
        node->lhs = cur_node;

        return node;
    }
    else
    {
        exit(1);
    }


}

Node *isArgumentNode(Token **cur_token,Env **cur_env,Node *cur_node)
{
    Node *argument_node = NULL;

    if(match(cur_token,"int"))
    {
        argument_node = isDeclaration(cur_token,cur_env,cur_node,INT);   
    }
    else if(match(cur_token,"char"))
    {
        argument_node =  isDeclaration(cur_token,cur_env,cur_node,CHAR);
    }
    else if(match(cur_token,"void"))
    {
        argument_node = createNode(NULL,NULL,ND_NULL);
    }
    else
    {
        exit(1);
    }

    match(cur_token,",");

    return argument_node;

}

Node *isFunctionDefination(Token **cur_token,Env **cur_env,Node *cur_node)
{

}

Node *isInitializetion(Token **cur_token,Env **cur_env,Node *cur_node)
{

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
        char *variable_name = readStr(cur_token);
        node = createVariableNode(variable_name,kind,cur_env);
    }

    node->lhs = cur_node;
    node->rhs = NULL;

    return node;

}

Node *isAssign(Token **cur_token,Env **cur_env,Node *cur_node)
{
    if((*cur_token)->next->kind != TK_SYMBOL)
    {
        return NULL;
    }

    if(!isSameString((*cur_token)->next->str,"="))
    {
        return NULL;
    }

    if(findEnv(cur_env,(*cur_token)->str))
    {
        Node *node = calloc(1,sizeof(Node));
        node->kind = ND_ASSIGN;
        node->str = readStr(cur_token);

        match(cur_token,"=");

        node->rhs = expr(cur_token,cur_env,NULL);
        node->lhs = cur_node;
        expect(cur_token,";");
        return node;
    }
    else
    {
        return NULL;
    }
}

Node *isReturn(Token **cur_token,Env **cur_env,Node *cur_node)
{
    if(match(cur_token,"return"))
    {
        Node *node = createNode(NULL,NULL,ND_RETURN);
        node->lhs = cur_node;
        node->rhs = expr(cur_token,cur_env,NULL);
        expect(cur_token,";");
        return node;
    }
    else 
    {
        return NULL;
    }
}

Node *isCondition(Token **cur_token,Env **cur_env,Node *cur_node)
{
    Node *condition_node = NULL;

    if(isSameToken(&(*cur_token)->next,"=="))
    {
        condition_node = createNode(NULL,NULL,ND_EQU);
        condition_node->lhs = expr(cur_token,cur_env,NULL);
        expect(cur_token,"==");
        condition_node->rhs = expr(cur_token,cur_env,NULL);
        return condition_node;
    }

    if(isSameToken(&(*cur_token)->next,">"))
    {
        condition_node = createNode(NULL,NULL,ND_BS);
        condition_node->lhs = expr(cur_token,cur_env,NULL);
        expect(cur_token,">");
        condition_node->rhs = expr(cur_token,cur_env,NULL);
        return condition_node;
    }

    if(isSameToken(&(*cur_token)->next,"<"))
    {
        condition_node = createNode(NULL,NULL,ND_SB);
        condition_node->lhs = expr(cur_token,cur_env,NULL);
        expect(cur_token,"<");
        condition_node->rhs = expr(cur_token,cur_env,NULL);
        return condition_node;
    }

    return NULL;
}

Node *ifStatement(Token **cur_token,Env **cur_env,Node *cur_node)
{
    if(match(cur_token,"if"))
    {
        expect(cur_token,"(");
        Node *condition_node = isCondition(cur_token,cur_env,NULL);
        expect(cur_token,")");
        expect(cur_token,"{");
        Node *true_syntax_node = Parse(cur_token,cur_env,NULL);
        Node *syntax_node = createNode(true_syntax_node,NULL,ND_NULL);
        Node *jointNode = createNode(condition_node,syntax_node,ND_IGNORE);
        Node *ifNode = createNode(cur_node,jointNode,ND_IF);
        expect(cur_token,"}");

        if(match(cur_token,"else"))
        {
            expect(cur_token,"{");
            Node *false_syntax_node = Parse(cur_token,cur_env,NULL);
            syntax_node->rhs = false_syntax_node;
            expect(cur_token,"}");
            return ifNode;
        }
    
        return ifNode;
        
    }
    else
    {
        return NULL;
    }
}

Node *isWhileStatement(Token **cur_token,Env **cur_env,Node *cur_node)
{
    if(match(cur_token,"while"))
    {
        expect(cur_token,"(");
        Node *condition_node = isCondition(cur_token,cur_env,NULL);
        expect(cur_token,")");
        expect(cur_token,"{");
        printf("saiki parse\n");
        Node *syntax_node = Parse(cur_token,cur_env,NULL);
        printf("kokomade\n");
        expect(cur_token,"}");
        
        Node *jointNode = createNode(condition_node,syntax_node,ND_IGNORE);

        Node *while_node = createNode(cur_node,jointNode,ND_WHILE);

        return while_node;
    }

    return NULL;
}