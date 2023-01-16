#include "../../include/Analyzer/AnalyzerTools.h"

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
            printf("herehehrere\n");
            printf("%s\n",(*cur_env)->id);
            if((*cur_env)->offset == 0)
            {
                (*cur_env)->offset = offset + capacity[(*cur_node)->type];
                offset = (*cur_env)->offset;
            }
            printf("offset is%d\n",(*cur_env)->offset);
            
            break;
        case ND_IF:
            (*cur_node)->hierarchy = over_all_hierarchy;
            over_all_hierarchy += 4;
            break;

    }

    return;
}