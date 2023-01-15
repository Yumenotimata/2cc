#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "TokenizerTools.h"
#include "Token.h"
#include <stdio.h>
#include <ctype.h>

    Token *Tokenize(FILE *compile_file);
    extern FILE *out_fp;

#endif