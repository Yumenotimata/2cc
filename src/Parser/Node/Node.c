#include "../../../include/Parser/Node/Node.h"

const char *node_kind[20] =
{
    "ND_NUM","ND_ADD","ND_SUB","ND_MUL","ND_DIV","ND_CALC","ND_VAL","ND_INIT","ND_ASSIGN","ND_RETURN","ND_EQU","ND_IF","ND_IGNORE","ND_NULL","ND_SB","ND_BS","ND_WHILE","ND_FUNC","ND_ARGUMENT","ND_CALL"
};

const char *type_kind[5] = 
{
    "INT","CHAR","INT_PTR","CHAR_PTR","VOID"
};

int capacity[4] =
{
    4,1,4,1
};

Node *createNumNode(int val)
{
    Node *node = calloc(1,sizeof(Node));
    node->rhs = NULL;
    node->lhs = NULL;
    node->val = val;
    node->kind = ND_NUM;
    return node;
}

Node *createNode(Node *lhs,Node *rhs,NodeKind kind)
{
    Node *node = calloc(1,sizeof(Node));
    node->lhs = lhs;
    node->rhs = rhs;
    node->kind = kind;
    return node;
}

Node *createVariableNode(char *variable_name,TypeKind type,Env **cur_env)
{
    Node *node = calloc(1,sizeof(Node));
    node->lhs = NULL;
    node->rhs = NULL;
    node->kind = ND_VAL;
    node->type = type;
    node->str = variable_name;

    putEnv(cur_env,variable_name,type);
    
    return node;
}

Node *createStrNode(char *str)
{
    Node *node = calloc(1,sizeof(Node));
    node->lhs = NULL;
    node->rhs = NULL;
    node->kind = ND_VAL;
    node->str = str;

    return node;
}