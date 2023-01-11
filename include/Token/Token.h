#ifndef TOKEN_H
#define TOKEN_H

    #include "TokenizerTools.h"
    #define TK_NUM "TK_NUM"
    #define TK_STR "TK_STR"
    #define TK_SYMBOL "TK_SYMBOL"
 
    typedef struct Token Token;
    struct Token{
        Token *next;
        char *kind;
        char *str;
        int val;
    };
    
    Token *token;

    void SetNumToken(int val);
    void SetStrToken(char *set_str);

#endif