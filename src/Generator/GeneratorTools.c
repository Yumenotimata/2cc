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
    fprintf(out_fp,"    add rax,rdi\n    push rax\n");

    return;
}

void genSub(Node *cur_node,Env **cur_env)
{
    genChild(cur_node,cur_env);

    printf("    sub rax,rdi\n");
    printf("    push rax\n");
    fprintf(out_fp,"    sub rax,rdi\n    push rax\n");

    return;
}

void genMul(Node *cur_node,Env **cur_env)
{
    genChild(cur_node,cur_env);

    printf("    imul rax,rdi\n");
    printf("    push rax\n");
    fprintf(out_fp,"    imul rax,rdi\n    push rax\n");

    return;
}

void genDiv(Node *cur_node,Env **cur_env)
{
    genChild(cur_node,cur_env);

    printf("    cqo\n");
    printf("    idiv rdi\n");
    printf("    push rax\n");
    fprintf(out_fp,"    cqo\n    idiv rdi\n    push rax\n");

    return;
}

void genVal(Node *cur_node,Env **cur_env)
{
    switch(cur_node->kind)
    {
        case ND_NUM:
            printf("    push %d\n",cur_node->val);
            fprintf(out_fp,"    push %d\n",cur_node->val);
            break;
    }

    return;
}


void genChild(Node *cur_node,Env **cur_env)
{
    genVal(cur_node->lhs,cur_env);
    genVal(cur_node->rhs,cur_env);

    if((cur_node->lhs->kind == ND_NUM) && (cur_node->rhs->kind != ND_NUM))
    {
        printf("    pop rax\n");
        printf("    pop rdi\n");
        fprintf(out_fp,"    pop rax\n    pop rid\n");
    }else
    {
        printf("    pop rdi\n");
        printf("    pop rax\n");
        fprintf(out_fp,"    pop rdi\n    pop rax\n");
    }
}

void genInitializetion(Node *cur_node,Env **cur_env)
{
    printf("gen initializetion\n");

    findEnv(cur_env,cur_node->lhs->str);

    if(cur_node->rhs != NULL)
    {
        GenerateCalc(cur_node->rhs,cur_env);
        printf("    pop rax\n");
        printf("    mov [rbp-%d],rax\n",(*cur_env)->offset);
        fprintf(out_fp,"    pop rax\n    mov [rbp-%d],rax\n",(*cur_env)->offset);
    }else
    {
        printf("    mov [rbp-%d],0\n",(*cur_env)->offset);
        fprintf(out_fp,"    mov [rbp-%d],0\n",(*cur_env)->offset);
    }
}