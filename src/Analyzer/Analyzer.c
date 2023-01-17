#include "../../include/Analyzer/Analyzer.h"
#include "../../include/Analyzer/AnalyzerTools.h"
#include "../../include/Parser/Node/Node.h"



void Analyze(Node **cur_node,Env **cur_env)
{
    if((*cur_node) == NULL)
    {
        return;
    }

    Analyze(&(*cur_node)->lhs,cur_env);
    Analyze(&(*cur_node)->lhs,cur_env);
    
    printf("Analyze kind is %s\n",node_kind[(*cur_node)->kind]);
    switch((*cur_node)->kind)
    {
        case ND_FUNC:
            int *offset = calloc(1,sizeof(int));
            (*offset) = 0;
            printf("si\n");
            (*cur_node)->shift = analyzeOffset_s(cur_node,cur_env,offset);
            printf("shift is %d\n",(*cur_node)->shift);
            return;
    }
}

