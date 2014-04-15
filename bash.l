%{
#include <cstdlib>
#include "bash_defines.h"
%}

%option noyywrap
%option debug

digit [0-9]
nl    [\r\n]

%%

"+"                     return PLUS;
"-"                     return MINUS;
{digit}*\.?{digit}+     {
                            yylval.dval = std::atof(yytext);
                            return NUM;
                        }
{nl}                    return NL;
.                       /* ignore */

