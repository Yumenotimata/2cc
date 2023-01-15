#ifndef GENERATOR_TOOLS_H
#define GENERATOR_TOOLS_H

    #include <stdbool.h>
    #include <stdio.h>
    #include "../../include/Parser/Node/Node.h"
    #include "../../include/Env/Env.h"
    #include "../../include/Generator/Generator.h"
    #include "../../include/Token/Tokenizer.h"

    bool isCaluclation(Node *cur_node);
    void genChild(Node *cur_node,Env **cur_env);
    void genVal(Node *cur_node,Env **cur_env);
    void genAdd(Node *cur_node,Env **cur_env);
    void genSub(Node *cur_node,Env **cur_env);
    void genMul(Node *cur_node,Env **cur_env);
    void genDiv(Node *cur_node,Env **cur_env);
    void genInitializetion(Node *cur_node,Env **cur_env);
    void genAssign(Node *cur_node,Env **cur_env);
    void genNum(Node *cur_node,Env **cur_env);
    void genReturn(Node *cur_node,Env **cur_env);
    
#endif