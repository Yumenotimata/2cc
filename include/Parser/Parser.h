#ifndef PARSER_H
#define PARSER_H

    #include "Node/Node.h"
    #include "../../include/Token/Token.h"
    #include "../../include/Tools/StringTool.h"
    #include "../../include/Parser/ParserTools.h"
    #include "../../include/Env/Env.h"
    #include <string.h>
    #include <stdio.h>

    Node *Parse(Token **token,Env **env,Node *cur_node);
    void addaptNode(Node *cur_node,Node *addapt_node);
    void addContext(Node **cur_node,NodeKind kind);
    void handleEndNode(Node **cur_node);

#endif