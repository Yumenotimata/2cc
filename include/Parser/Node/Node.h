#ifndef NODE_H
#define NODE_H

    #include <stdio.h>
    #include <stdlib.h>

    extern const char *node_kind[];
    extern const char *type_kind[];
    extern int capacity[];

    typedef enum
    {
        INT,
        CHAR,
        INT_PTR,
        CHAR_PTR,
    }TypeKind;


    typedef struct Env Env;
    struct Env
    {
        Env *next;
        Env *head;
        int offset;
        char *id;
        TypeKind type;
    };

    typedef enum
    {
        ND_NUM,
        ND_ADD,
        ND_SUB,
        ND_MUL,
        ND_DIV,
        ND_CALC,
        ND_VAL,
        ND_INIT,
        ND_ASSIGN,
        ND_RETURN,
    }NodeKind;

    typedef struct Node Node;
    struct Node
    {
        Node *rhs;
        Node *lhs;
        NodeKind kind;
        TypeKind type;
        int val;   
        char *str; 
    };

    Node *createNumNode(int val);
    Node *createNode(Node *lhs,Node *rhs,NodeKind kind);
    Node *createVariableNode(char *variable_name,TypeKind type,Env **cur_env);
    Node *createStrNode(char *str);

#endif