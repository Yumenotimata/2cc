#ifndef NODE_H
#define NODE_H

    typedef struct Node Node;
    struct Node
    {
        Node *rhs;
        Node *lhs;
        char *kind;
        int val;    
    };

#endif