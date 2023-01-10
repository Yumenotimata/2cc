#ifndef COMPILER_H
#define COMPILER_H

#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/token.h"
#include "../include/tokenizer.h"
#include "../include/tools/tokenizerTools.h"
#include "../include/cabinet.h"
#include "../include/parser.h"
#include "../include/tools/parseTools.h"
#include "../include/codeGenerator.h"
#include "../include/tools/codeGeneratorTools.h"
#include "../include/typeList.h"


#define DEBUG_ON
#ifdef DEBUG_ON
#define DEBUG_LOG(...)    printf("%s(%d) %s:",__FILE__,__LINE__,__func__),printf(__VA_ARGS__)
#else
#define DEBUG_LOG(...)  
#endif

#endif