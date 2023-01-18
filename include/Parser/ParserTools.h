#ifndef PARSER_TOOLS_H
#define PARSER_TOOLS_H

    #include "../../include/Token/Token.h"
    #include "../../include/Parser/Node/Node.h"
    #include "../Generator/Generator.h"
    #include "../../include/Env/Env.h"
    #include "Parser.h"
    #include <stdio.h>

    Node *expr(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *mul(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *primary(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *parseStr(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *isInitializetion(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *isFunctionDefination(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *isDefination(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *isDeclaration(Token **cur_token,Env **cur_env,Node *cur_node,TypeKind kind);
    Node *isAssign(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *isReturn(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *isCondition(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *ifStatement(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *isWhileStatement(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *isArgumentNode(Token **cur_token,Env **cur_env,Node *cur_node);
    Node *isFunctionNode(Token **cur_token,Env **cue_env,Node *cur_node);
    Node *funcArgument(Token **cur_token,Env **cur_env,Node *cur_node);

#endif