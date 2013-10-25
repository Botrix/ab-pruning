%{
#include <string>
#include "node.h"
#include "parser.hpp"
#define SAVE_TOKEN yyval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yyval.token = t)
extern "C" int yywrap() { }
%}

%%
[ \t\n]                         ;
['][a-zA-Z_][a-zA-Z0-9_]*[']    SAVE_TOKEN; return TSTRING;
[-]?[0-9]+                      SAVE_TOKEN; return TINTEGER;
"("                             return TOKEN(TLPAREN);
")"                             return TOKEN(TRPAREN);
.                               printf("Unknown token!\n"); yyterminate();

%%
