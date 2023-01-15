#include "../../include/Analyzer/Analyzer.h"
#include "../../include/Analyzer/AnalyzerTools.h"
#include "../../include/Parser/Node/Node.h"

void Analyze(Node **cur_node,Env **cur_env)
{
    analyzeOffset(cur_node,cur_env);
}

