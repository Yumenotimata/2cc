#include "../../../include/Parser/Node/Node.h"

const char *node_kind[6] =
{
    "ND_NUM","ND_ADD","ND_SUB","ND_MUL","ND_DIV","ND_CALC"
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
