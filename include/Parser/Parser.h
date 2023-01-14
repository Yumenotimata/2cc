#ifndef PARSER_H
#define PARSER_H

    #include "Node/Node.h"
    #include "../../include/Token/Token.h"
    #include "../../include/Tools/StringTool.h"
    #include "../../include/Parser/ParserTools.h"
    #include "../../include/Env/Env.h"
    #include <string.h>
    #include <stdio.h>

    Node *Parse(Token **token,Env **env);

#endif