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
%token SEMI
%token <word> WORD
%token NUMBER

%type <command> inputunit command list list0 list1 simple_list simple_list1 simple_command shell_command
%type <redirect> redirection redirections

%start inputunit

%left SEMI '\n' yacc_EOF
%right PIPE

%%

inputunit:	simple_list '\n' 	/* our SIMPLE_LIST */
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
			  $$ = make_redirection (1, r_output_direction, redir); /*make_redirection is our function */
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

simple_command_element: WORD
			{ $$.word = $1; $$.redirect = 0; }
	|	redirection
			{ $$.redirect = $1; $$.word = 0; }
	;

simple_command:	simple_command_element
			{ $$ = make_simple_command ($1, (COMMAND *)NULL); }
	|	simple_command simple_command_element
			{ $$ = make_simple_command ($2, $1); }
	;

command:	simple_command
			{ $$ = clean_simple_command ($1); }
	|	shell_command
			{ $$ = $1; }
	;

shell_command:	'(' list ')'
			{ $2->subshell = 1; $$ = $2; }
		;

list:		newlines list0
			{ $$ = $2; }
	;

list0:		list1
	|	list1 '\n' newlines
	//|	list1 '&' newlines
	//		{ $$ = command_connect ($1, 0, '&'); }
	|	list1 ';' newlines

	;

list1:	//	list1 AND_AND newlines list1
	//		{ $$ = command_connect ($1, $4, AND_AND); }
	//|	list1 OR_OR newlines list1
	//		{ $$ = command_connect ($1, $4, OR_OR); }
	//|	list1 '&' newlines list1
	//		{ $$ = command_connect ($1, $4, '&'); }
	|	list1 ';' newlines list1
			{ $$ = command_connect ($1, $4, ';'); }
	|	list1 '\n' newlines list1
			{ $$ = command_connect ($1, $4, ';'); }
	|	list1 '|' newlines list1
			{ $$ = command_connect ($1, $4, '|'); }
	|	command
	;


list_terminator:'\n'
	|	';'
	|	yacc_EOF
	;

newlines:
	|	newlines '\n'
	;

simple_list:	simple_list1
	//|	simple_list1 '&'
	//		{ $$ = command_connect ($1, (COMMAND *)NULL, '&'); }
	|	simple_list1 ';'
	;

simple_list1:	//simple_list1 AND_AND newlines simple_list1
		//	{ $$ = command_connect ($1, $4, AND_AND); }
	//|	simple_list1 OR_OR newlines simple_list1
	//		{ $$ = command_connect ($1, $4, OR_OR); }
	//|	simple_list1 '&' simple_list1
	//		{ $$ = command_connect ($1, $3, '&'); }
	|	simple_list1 ';' simple_list1
			{ $$ = command_connect ($1, $3, ';'); }
	|	simple_list1 '|' newlines simple_list1
			{ $$ = command_connect ($1, $4, '|'); }
	|	command
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
