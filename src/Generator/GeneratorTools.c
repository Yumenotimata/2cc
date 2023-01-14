#include "../../include/Generator/GeneratorTools.h"


bool isCaluclation(Node *cur_node)
{
    if (cur_node->kind == ND_DIV || cur_node->kind == ND_MUL|| cur_node->kind == ND_ADD|| cur_node->kind == ND_SUB)
	{
		return true;
	}

	return false;
}

void genAdd(Node *cur_node,Env **cur_env)
{
    genChild(cur_node,cur_env);

    printf("    add rax,rdi\n");
    printf("    push rax\n");

    return;
}

void genSub(Node *cur_node,Env **cur_env)
{
    genChild(cur_node,cur_env);

    printf("    sub rax,rdi\n");
    printf("    push rax\n");

    return;
}

void genMul(Node *cur_node,Env **cur_env)
{
    genChild(cur_node,cur_env);

    printf("    mul rax,rdi\n");
    printf("    push rax\n");

    return;
}

void genDiv(Node *cur_node,Env **cur_env)
{
    genChild(cur_node,cur_env);

    printf("    div rax,rdi\n");
    printf("    push rax\n");

    return;
}

void genVal(Node *cur_node,Env **cur_env)
{
    switch(cur_node->kind)
    {
        case ND_NUM:
            printf("    push %d\n",cur_node->val);
            break;
    }

    return;
}

void genNum(Node *cur_node,Env **cur_env)
{
    printf("    push %d\n",cur_node->val);
}

void genChild(Node *cur_node,Env **cur_env)
{
    genVal(cur_node->lhs,cur_env);
    genVal(cur_node->rhs,cur_env);

    if((cur_node->lhs->kind == ND_NUM) && (cur_node->rhs->kind != ND_NUM))
    {
        printf("    pop rax\n");
        printf("    pop rdi\n");
    }else
    {
        printf("    pop rdi\n");
        printf("    pop rax\n");
    }
}