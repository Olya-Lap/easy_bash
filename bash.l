%{
#include <cstdlib>
#include "bash_defines.h"
%}

%option noyywrap
%option debug

WORD [\w+]

%%

"|"                     return PIPE;
">"                     return GREAT;
"<"			return LESS;
";"                     return SEMI;
"<"			return LESS;
{digit}*\.?{digit}+     {
                            yylval.dval = std::atof(yytext);
                            return NUM;
                        }
.                       /* ignore */

