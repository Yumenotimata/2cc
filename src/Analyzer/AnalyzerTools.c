#include "../../include/Analyzer/AnalyzerTools.h"

int analyzeOffset_s(Node **cur_node,Env **cur_env,int *offset)
{
    static int over_all_hierarchy;

    if((*cur_node)==NULL)
    {
        return (*cur_env)->offset;
    }

    analyzeOffset_s(&((*cur_node)->lhs),cur_env,offset);
    analyzeOffset_s(&((*cur_node)->rhs),cur_env,offset);

    switch((*cur_node)->kind)
    {
        case ND_VAL:
            findEnv(cur_env,(*cur_node)->str);
            if((*cur_env)->offset == 0)
            {
                (*cur_env)->offset = (*offset) + capacity[(*cur_node)->type];
                (*offset) = (*cur_env)->offset;
            }
            break;
        case ND_IF:
            (*cur_node)->hierarchy = over_all_hierarchy;
            over_all_hierarchy += 4;
            break;
        case ND_WHILE:
            (*cur_node)->hierarchy = over_all_hierarchy;
            over_all_hierarchy += 4;
            break;
    }
    return (*cur_env)->offset;
}

void analyzeOffset(Node **cur_node,Env **cur_env)
{
    static int offset;
    static int over_all_hierarchy;

    if((*cur_node)==NULL)
    {
        return;
    }

    analyzeOffset(&((*cur_node)->lhs),cur_env);
    analyzeOffset(&((*cur_node)->rhs),cur_env);

    switch((*cur_node)->kind)
    {
        case ND_VAL:
            findEnv(cur_env,(*cur_node)->str);
            if((*cur_env)->offset == 0)
            {
                (*cur_env)->offset = offset + capacity[(*cur_node)->type];
                offset = (*cur_env)->offset;
            }
            break;
        case ND_IF:
            (*cur_node)->hierarchy = over_all_hierarchy;
            over_all_hierarchy += 4;
            break;
        case ND_WHILE:
            (*cur_node)->hierarchy = over_all_hierarchy;
            over_all_hierarchy += 4;
            break;
    }
    return;
}