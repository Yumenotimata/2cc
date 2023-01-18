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

    printf("    imul rax,rdi\n");
    printf("    push rax\n");

    return;
}

void genDiv(Node *cur_node,Env **cur_env)
{
    genChild(cur_node,cur_env);

    printf("    cqo\n");
    printf("    idiv rdi\n");
    printf("    push rax\n");

    return;
}

void genNum(Node *cur_node,Env **cur_env)
{
    switch(cur_node->kind)
    {
        case ND_NUM:
            printf("    push %d\n",cur_node->val);
            return;
    }

    return;
}

void genVal(Node *cur_node,Env **cur_env)
{
    findEnv(cur_env,cur_node->str);
    printf("    push [rbp-%d]\n",(*cur_env)->offset);
}


void genChild(Node *cur_node,Env **cur_env)
{

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

void genInitializetion(Node *cur_node,Env **cur_env)
{
    findEnv(cur_env,cur_node->lhs->str);

    if(cur_node->rhs != NULL)
    {
        GenerateCalc(cur_node->rhs,cur_env);
        printf("    pop rax\n");
        printf("    mov [rbp-%d],rax\n",(*cur_env)->offset);
    }else
    {
        printf("    mov [rbp-%d],0\n",(*cur_env)->offset);
    }
}

void genAssign(Node *cur_node,Env **cur_env)
{
    GenerateCalc(cur_node->rhs,cur_env);
    findEnv(cur_env,cur_node->str);
    printf("    pop rax\n");
    printf("    mov [rbp-%d],rax\n",(*cur_env)->offset);

    return;
}

void genReturn(Node *cur_node,Env **cur_env)
{
    GenerateCalc(cur_node->rhs,cur_env);
    printf("    pop rbx\n");
    return;
}

void genIfStatement(Node *cur_node,Env **cur_env)
{
    genCondition(cur_node->rhs->lhs,cur_env);
    if(cur_node->rhs->lhs->kind == ND_EQU)
    {
        printf("    jne .L%d\n",cur_node->hierarchy);
    }
    else if(cur_node->rhs->lhs->kind == ND_BS)
    {
        printf("    jle .L%d\n",cur_node->hierarchy);
    }
    else if(cur_node->rhs->lhs->kind == ND_SB)
    {
        printf("    jg .L%d\n",cur_node->hierarchy);
    }
    GenerateCode(cur_node->rhs->rhs->lhs,cur_env);
    printf("    jmp .L%d\n",cur_node->hierarchy + 1);
    printf(".L%d:\n",cur_node->hierarchy);
    GenerateCode(cur_node->rhs->rhs->rhs,cur_env);
    printf(".L%d:\n",cur_node->hierarchy + 1);
    return;

}

void genWhileStatement(Node *cur_node,Env **cur_env)
{
    printf(".L%d:\n",cur_node->hierarchy);
    genCondition(cur_node->rhs->lhs,cur_env);
    if(cur_node->rhs->lhs->kind == ND_EQU)
    {
        printf("    jne .L%d\n",cur_node->hierarchy+1);
    }
    else if(cur_node->rhs->lhs->kind == ND_BS)
    {
        printf("    jle .L%d\n",cur_node->hierarchy+1);
    }
    else if(cur_node->rhs->lhs->kind == ND_SB)
    {
        printf("    jg .L%d\n",cur_node->hierarchy+1);
    }
    GenerateCode(cur_node->rhs->rhs,cur_env);
    printf("    jmp .L%d\n",cur_node->hierarchy);
    printf(".L%d:\n",cur_node->hierarchy + 1);

    return;

}

void genCondition(Node *cur_node,Env **cur_env)
{
    GenerateCalc(cur_node->lhs,cur_env);
    GenerateCalc(cur_node->rhs,cur_env);

    printf("    pop rdi\n");
    printf("    pop rax\n");
    printf("    cmp rax,rdi\n");

    return;
}