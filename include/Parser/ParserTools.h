#ifndef PARSER_TOOLS_H
#define PARSER_TOOLS_H

    #include "../../include/Token/Token.h"
    #include "../../include/Parser/Node/Node.h"
    #include "../../include/Env/Env.h"
    #include <stdio.h>

    Node *expr(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *mul(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *primary(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *parseStr(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *isInitializetion(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *isDeclaration(Token **cur_token,Env **cur_env,Node *cur_node,TypeKind kind);

#endif