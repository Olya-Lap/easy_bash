%{
#include "bash_defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
%}

%option noyywrap
%option debug

nchar [a-zA-Z_0-9]
digit [0-9]
%%

"|"         return PIPE;
">"         return GREAT;
"<"			return LESS;
";"         return SEMI;
{digit}+	{ cout << "number"; }
{nchar}+	{ system(yytext);  }
%%
