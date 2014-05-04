%{
#include "bash_defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
%}

%option noyywrap
%option debug
%option yylineno

nchar [a-zA-Z_0-9]
digit [0-9]
%%

[#].*       ; // comment
"|"         return PIPE;
">"         return GREAT;
"<"			return LESS;
";"         return SEMI;
"&"			return AND;
{digit}+	{ cout << "number"; }
{nchar}+	{ system(yytext);  }
.           { printf("Syntax error in line %d\n", yylineno); return *yytext; }
%%
