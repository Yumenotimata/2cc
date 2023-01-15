#ifndef TOKEN_H
#define TOKEN_H

    #include <stddef.h>
    #include <stdbool.h>
    #include "../../include/Token/TokenizerTools.h"
    #include "../../include/Tools/StringTool.h"

    typedef enum
    {
        TK_NUM,
        TK_STR,
        TK_EOF,
        TK_SYMBOL,
        TK_EOS,
    }TokenKind;

    typedef struct Token Token;
    struct Token
    {
        Token *next;
        TokenKind kind;
        char *str;
        int val;
    };

    extern const char *token_kind[];

    void SetNumToken(Token *token,int val);
    void SetStrToken(Token *token,char **set_str);
    void SetSymToken(Token *token,char **set_symbol);
    void ShowToken(Token *token);
    bool match(Token **token,char *expect_str);
    int readNum(Token **cur_token);
    char *readStr(Token **cur_token);

#endif