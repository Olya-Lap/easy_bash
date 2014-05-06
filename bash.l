%{
#include "bash_defines.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include<readline/readline.h>
#include<readline/history.h>
#include<string>
#include<vector>
using namespace std;
static int get_input(char *buf, int size);
#define YY_INPUT(buf,result,max_size) result = get_input(buf, max_size);
%}

%option noyywrap
%option debug
%option yylineno

nchar [a-zA-Z_0-9]
digit [0-9]
command [a-zA-Z][a-zA-Z_0-9]*
filename [a-zA-Z_0-9 \-\$\&\)\(\.\/]+
%%

[#].*$      ; // comment
"|"         return PIPE;
">"         return GREAT;
"<"			return LESS;
";"         return SEMI;
"&"			return AND;
">>"		return GREAT_GREAT;
"<<"		return LESS_LESS;
{digit}+	{yylval.number = atoi(yytext); return NUMBER; }
{command}	{yylval.word = (WORD_DESC *)malloc (sizeof (WORD_DESC)); yylval.word->word = strdup(yytext); return WORD; }
[ \t]+		;
.           { printf("Syntax error in line %d\n", yylineno); }
%%

void GetPrompt(string& opd)
{
    opd.assign("my_bash@:");
    char currwd[256];
    getcwd(currwd, 256);
    opd.append(currwd).append("$ ");
}

static int get_input(char *buf, int size)
{
    char *line;
    int len=0;
    if (feof(yyin))
            return YY_NULL;
    string prompt;
    GetPrompt(prompt);
    line = readline(prompt.c_str());
    if (!line)
            return YY_NULL;
    strncpy(buf,line,size-2);
    len=strlen(line);
    len=(len)>(size-2)?(size-2):len;
    buf[len]='\0';
    add_history(buf);
    buf[len]='\n';
    buf[len+1]='\0';
    free(line);
    return strlen(buf);
}