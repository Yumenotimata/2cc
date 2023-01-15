#include "../../include/Generator/Generator.h"

void GenerateCode(Node *cur_node,Env **cur_env)
{
    if(cur_node == NULL)
    {
        return;
    }
    
    if(cur_node->kind == ND_IGNORE)
    {
        printf("ND_IGUNORE\n");
        //return;
    }

    GenerateCode(cur_node->lhs,cur_env);
    GenerateCode(cur_node->rhs,cur_env);

    printf("node kind is %s\n",node_kind[cur_node->kind]);

    // switch(cur_node->kind)
    // {
    //     case ND_INIT:
    //         genInitializetion(cur_node,cur_env);
    //         break;
    //     case ND_ASSIGN:
    //         genAssign(cur_node,cur_env);
    //         break;
    //     case ND_RETURN:
    //         genReturn(cur_node,cur_env);
    //         break;
    //     case ND_IF:
    //         genIfStatement(cur_node,cur_env);
    //         break;
    // }

    return;

}

void GenerateCalc(Node *cur_node,Env **cur_env)
{
    if(cur_node == NULL)
    {
        return;
    }

    GenerateCalc(cur_node->lhs,cur_env);
    GenerateCalc(cur_node->rhs,cur_env);

    switch(cur_node->kind)
    {
        case ND_ADD:
            genAdd(cur_node,cur_env);
            break;
        case ND_SUB:
            genSub(cur_node,cur_env);
            break;
        case ND_MUL:
            genMul(cur_node,cur_env);
            break;
        case ND_DIV:
            genDiv(cur_node,cur_env);
            break;
        case ND_NUM:
            genNum(cur_node,cur_env);
            break;
        case ND_VAL:
            genVal(cur_node,cur_env);
            break;

    }

    return;

}