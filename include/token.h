#ifndef TOKEN_H
#define TOKEN_H

#define TK_NUM "TK_NUM"
#define TK_SYMBOL "TK_SYMBOL"
#define TK_STR "TK_STR"
#define TK_END "TK_END"

typedef struct Token Token;
struct Token
{
	Token* next;
	char* str;
	char* kind;
	int val;
};

#endif