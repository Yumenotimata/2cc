#include "../../include/Env/Env.h"

    Env *initEnv(void)
    {
        Env *table = calloc(1,sizeof(Env));
        table->head = table;
        table->next = NULL;
        return table;
    }

    void putEnv(Env **cur_env,char *id,TypeKind type)
    {
        while(((*cur_env)->next) != NULL)
        {
            (*cur_env) = (*cur_env)->next;
        }

        (*cur_env)->id = id;
        (*cur_env)->type = type;

        Env *new_env = calloc(1,sizeof(Env));
        new_env->next = NULL;
        new_env->head = (*cur_env)->head;
        (*cur_env)->next = new_env;
        (*cur_env) = (*cur_env)->next;

    }

    bool findEnv(Env **cur_env,char *serch_id)
    {
        Env *h_Env = *cur_env;
        (*cur_env) = (*cur_env)->head;

        while((*cur_env)->next != NULL)
        {
            if(isSameString(serch_id,(*cur_env)->id))
            {
                return true;
            }

            (*cur_env) = (*cur_env)->next;   
        }

        return false;
    }

    bool handleEnv(Env **cur_env,char *serch_id)
    {

    } 