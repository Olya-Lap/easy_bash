%{
#include <iostream>
#include <stdio.h>
#include "helper.h"
int yylex(void);
void yyerror(char const *);
static REDIRECTEE redir;
%}

%defines "bash_defines.h"

%union {
    double dval; 
    REDIRECT *redirect;
}

%token PIPE
%token GREAT
%token LESS
%token OQOUT
%token CQUOT
%token SEMI
%token <word> WORD ASSIGNMENT_WORD
%token NUMBER


%start inputunit

%left SEMI '\n' yacc_EOF
%right PIPE

%%

inputunit:	simple_list '\n' 	/* your SIMPLE_LIST */
			{
			  /* Case of regular command.  Discard the error
			     safety net,and return the command just parsed. */
			  global_command = $1;
			  eof_encountered = 0;
			  discard_parser_constructs (0);
			  YYACCEPT;
			}
	|	'\n'
			{
			  /* Case of regular command, but not a very
			     interesting one.  Return a NULL command. */
			  global_command = (COMMAND *)NULL;
			  YYACCEPT;
			}
	|
		error '\n'
			{
			  /* Error during parsing.  Return NULL command. */
			  global_command = (COMMAND *)NULL;
			  eof_encountered = 0;
			  discard_parser_constructs (1);
			  if (interactive)
			    {
			      YYACCEPT;
			    }
			  else
			    {
			      YYABORT;
			    }
			}
	|	yacc_EOF
			{
			  /* Case of EOF seen by itself.  Do ignoreeof or 
			     not. */
			  global_command = (COMMAND *)NULL;
			  handle_eof_input_unit ();
			  YYACCEPT;
			}
	;


redirection:	GREAT WORD
			{
			  redir.filename = $2;
			  $$ = make_redirection (1, r_output_direction, redir); /*make_redirection is your function */
			}
	|	LESS WORD
			{
			  redir.filename = $2;
			  $$ = make_redirection (0, r_input_direction, redir);
			}
	
	|	NUMBER GREAT WORD
			{
			  redir.filename = $3;
			  $$ = make_redirection ($1, r_output_direction, redir);
			}
	|	NUMBER LESS WORD
			{
			  redir.filename = $3;
			  $$ = make_redirection ($1, r_input_direction, redir);
			}

simple_command_element: WORD
			{ $$.word = $1; $$.redirect = 0; }
	|	ASSIGNMENT_WORD
			{ $$.word = $1; $$.redirect = 0; }
	|	redirection
			{ $$.redirect = $1; $$.word = 0; }
	;

redirections:	redirection
			{
			  $$ = $1;
			}
	|	redirections redirection
			{ 
			  register REDIRECT *t = $1;

			  while (t->next)
			    t = t->next;
			  t->next = $2; 
			  $$ = $1;
			}
	;

list_terminator: '\n'
		|	';'
		|	yacc_EOF
		;

newlines:
		|	newlines '\n'
		;

pipeline:
		pipeline '|' newlines pipeline
			{ $$ = command_connect ($1, $4, '|'); }
	|	command
			{ $$ = $1; }
	;

%%

void yyerror(char const *s)
{
    fprintf(stderr, "%s\n", s);
}

int main(void)
{
    return yyparse();
}
