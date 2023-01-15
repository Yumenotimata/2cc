#ifndef ENV_H
#define ENV_H

    #include <stdbool.h>
    #include <stdio.h>
    #include "../Tools/StringTool.h"
    #include "../Parser/Node/Node.h"

    Env *initEnv(void);
    void putEnv(Env **cur_env,char *id,TypeKind kind);
    bool findEnv(Env **cur_env,char *serch_id);
    bool handleEnv(Env **cur_env,char *serch_id);     

#endif