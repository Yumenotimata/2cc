#ifndef GENERATOR_H
#define GENERATOR_H

    #include "../Parser/Node/Node.h"
    #include "../Env/Env.h"
    #include "GeneratorTools.h"


    void GenerateCode(Node *cur_node,Env **cur_env);

#endif