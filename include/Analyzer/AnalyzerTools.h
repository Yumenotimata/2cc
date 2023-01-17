#ifndef ANALYZER_TOOLS_H
#define ANALYZER_TOOLS_H

    #include "../Env/Env.h"
    #include "../Parser/Node/Node.h"

    void analyzeOffset(Node **cur_node,Env **cur_env);
    int analyzeOffset_s(Node **cur_node,Env **cur_env,int *offset);

#endif