#ifndef GENERATOR_H
#define GENERATOR_H

    #include "../Parser/Node/Node.h"
    #include "../Env/Env.h"
    #include "GeneratorTools.h"

    extern const char *arg_resister[];

    void GenerateCode(Node *cur_node,Env **cur_env);
    void GenerateCalc(Node *cur_node,Env **cur_env);
    void GenerateFunction(Node *cur_node,Env **cur_env);
    void generateArgument(Node *cur_node,Env **cur_env,int *arg_index);
    int countArgument(Node *cur_node);
    void genCall(Node *cur_node,Env **cur_env);
    void genCallArgment(Node *cur_node,Env **cur_env,int *arg_index);

#endif