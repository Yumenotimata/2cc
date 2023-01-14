#ifndef ENV_H
#define ENV_H

    #include <stdbool.h>
    #include <stdio.h>
    #include "../Tools/StringTool.h"

    typedef struct Env Env;
    struct Env
    {
        Env *next;
        Env *head;
        int offset;
        char *id;
    };

    Env *initEnv(void);
    void putEnv(Env **cur_env,char *id);
    bool findEnv(Env **cur_env,char *serch_id);
    bool handleEnv(Env **cur_env,char *serch_id);     

#endif