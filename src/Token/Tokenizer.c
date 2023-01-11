#include "../../include/Token/Tokenizer.h"

void Tokenize(FILE *compile_file)
{
    char *compile_file_str = fp2str(compile_file);
    printf("%s\n",compile_file_str);

    while(*compile_file_str != '\0')
    {
        if(isspace(*compile_file_str))
        {
            printf("skip space\n");
            compile_file_str++;
            continue;
        }
        else if(isdigit(*compile_file_str))
        {
            SetNumToken(strtol(compile_file_str,&compile_file_str,10));
            printf("set num token\n");
        }
        else if(ischar(*compile_file_str))
        {
            printf("set str token\n");
            SetStrToken(compile_file_str);
        }
        else if(issymbol(*compile_file_str))
        {
            printf("symbo");
            exit(1);
        }
        else
        {
            printf("unexpected token\n");
            exit(1);
        }

    }
}

