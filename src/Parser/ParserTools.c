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
            }
            break;
        case TK_STR:
            node = createStrNode(readStr(cur_token));
            break;

            break;
    }

    printf("parse return\n");
    return node;
}

Node *parseStr(Token **cur_token,Env **cur_env,Node *cur_node)
{
    Node *node = NULL;
    printf("parseStr\n");
    
    if((node = isDefination(cur_token,cur_env,cur_node)) != NULL)
    {
        printf("return isDefinnation\n");
        return node;
    }
    if((node = isAssign(cur_token,cur_env,cur_node)) != NULL)
    {
        printf("return isassignment\n");
        return node;
    }
    if((node = isReturn(cur_token,cur_env,cur_node)) != NULL)
    {
        printf("is return\n");
        return node;
    }
    if((node = ifStatement(cur_token,cur_env,cur_node)) != NULL)
    {
        printf("is ifStatement\n");
        return node;
    }
    if((node = isWhileStatement(cur_token,cur_env,cur_node)) != NULL)
    {
        printf("is WhileStatement\n");
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
        printf("is Initializetion\n");
        return node;
    }
    else if(match(cur_token,";"))
    {
        node->kind = ND_INIT;
        node->rhs = NULL;
        printf("is Initializetion\n");
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
        
        //Node *func_detail_node = createNode(NULL,NULL,ND_NULL);
        //func_detail_node->lhs = node->lhs;
        //func_detail_node->rhs = argument_node;
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
        printf("Isdefination error\n");
        exit(1);
    }


}

Node *isArgumentNode(Token **cur_token,Env **cur_env,Node *cur_node)
{
    Node *argument_node = NULL;

    if(match(cur_token,"int"))
    {
        argument_node = isDeclaration(cur_token,cur_env,cur_node,INT);   
         printf("%s\n",(*cur_token)->str); 
    }
    else if(match(cur_token,"char"))
    {
        argument_node =  isDeclaration(cur_token,cur_env,cur_node,CHAR);
    }
    else if(match(cur_token,"void"))
    {
        argument_node = createNode(NULL,NULL,ND_NULL);

        printf("%s\n",(*cur_token)->str);
        //exit(1);
    }
    else
    {
        printf("argument error\n");
        exit(1);
    }

    match(cur_token,",");

    return argument_node;

}

Node *isFunctionDefination(Token **cur_token,Env **cur_env,Node *cur_node)
{   //is Function?
    // if(!isSameToken(&((*cur_token)->next->next),"("))
    // {
    //     return NULL:
    // }
    
    // Node *node = createNode(NULL,NULL,ND_FUNC);
    // if(match(cur_token,"int"))
    // {
    //     node->lhs = isDeclaration(cur_token,cur_env,cur_node,INT);    
    // }
    // else if(match(cur_token,"char"))
    // {
    //     node->lhs =  isDeclaration(cur_token,cur_env,cur_node,CHAR);
    // }
    // else 
    // {
    //     return NULL;
    // }
    

}

Node *isInitializetion(Token **cur_token,Env **cur_env,Node *cur_node)
{
    // Node *node = calloc(1,sizeof(Node));
    // node->kind = ND_INIT;
    // printf("isInitializetion\n");

    // if(match(cur_token,"="))
    // {   
    //     node->rhs = expr(cur_token,cur_env,NULL);
    //     match(cur_token,";");
    //     printf("now node kind is %s\n",node_kind[node->kind]);
    //     return node;
    // }
    // else if(match(cur_token,";"))
    // {
    //     node->rhs = NULL;
    //     return node;
    // }

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

Node *isAssign(Token **cur_token,Env **cur_env,Node *cur_node)
{
    printf("isAssign\n");

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

    printf("not condition\n");
    return NULL;


    // if(!isSameString((*cur_token)->next->str,"=="))
    // {
    //     printf("not condition\n");
    //     return NULL;
    // }

    // Node *node = createNode(NULL,NULL,ND_EQU);
    // node->lhs = expr(cur_token,cur_env,NULL);
    // match(cur_token,"==");
    // node->rhs = expr(cur_token,cur_env,NULL);
    // return node;

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
        printf("if Statement false\n");
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