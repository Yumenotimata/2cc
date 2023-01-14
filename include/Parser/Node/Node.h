#ifndef NODE_H
#define NODE_H

    #include <stdio.h>
    #include <stdlib.h>
    
    extern const char *node_kind[];

    typedef enum
    {
        ND_NUM,
        ND_ADD,
        ND_SUB,
        ND_MUL,
        ND_DIV,
        ND_CALC,
    }NodeKind;

    typedef struct Node Node;
    struct Node
    {
        Node *rhs;
        Node *lhs;
        NodeKind kind;
        int val;    
    };

    Node *createNumNode(int val);
    Node *createNode(Node *lhs,Node *rhs,NodeKind kind);

#endif