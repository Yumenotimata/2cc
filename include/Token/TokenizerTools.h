#ifndef TOKENIZER_TOOLS_H
#define TOKENIZER_TOOLS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Token.h"


#define MAX_FILE_CHAR_SIZE 1024
//いい方法が思い浮かばなかった
#define MAX_STR_SIZE 34

    char *fp2str(FILE *compile_file);
    char *ConsumeStr(char **str);
    char *ConsumeSymbol(char **str);
    bool ischar(char ch);
    bool issymbol(char ch);
    

#endif