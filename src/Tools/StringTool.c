#include "../../include/Tools/StringTool.h"

bool isSameString(char *base_string,char *cmp_string)
{
    if(!memcmp(cmp_string,cmp_string,strlen(base_string)))
    {
        return true;
    }

    return false;
}