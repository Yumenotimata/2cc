#include "../../include/Parser/Parser.h"
#include "../../include/Token/Token.h"
#include "../../include/Tools/StringTool.h"
#include <string.h>

Node *Parse(Token **token)
{
    Node *node = calloc(1,sizeof(Node));
    Node *h_node = node;

    while(isSameString((*token)->kind,TK_EOF))
    {

    }

    return h_node;
}

