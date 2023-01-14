#include "../../include/Tools/StringTool.h"

bool isSameString(char *base_string,char *cmp_string)
{
    if(!memcmp(base_string,cmp_string,strlen(base_string)))
    {
        if(strlen(base_string) == strlen(cmp_string))
        {
            return true;
        }

        return false;
    }

    return false;
}