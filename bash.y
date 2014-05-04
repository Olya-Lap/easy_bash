%{
#include <stdio.h>
#include "functions.c"
#define YYDEBUG 1
#define YYPRINT(file, type, value) fprintf(file, "%d", value);
#define CMD_WANT_SUBSHELL  0x01	/* User wants a subshell: ( command ) */
int yylex(void);
void yyerror(char const *);
int interactive = 1;
extern int eof_encountered;
extern int line_number;
static REDIRECTEE redir;
%}

%defines "bash_defines.h"

%union {
  WORD_DESC *word;		/* the word that we read. */
  int number;			/* the number that we read. */
  COMMAND *command;
  REDIRECT *redirect;
  ELEMENT element;
}

%token PIPE
%token GREAT
%token LESS
%token SEMI
%token <word> WORD
%token <number> NUMBER

%type <command> inputunit command pipeline
%type <command> list list0 list1 simple_list simple_list1
%type <command> simple_command shell_command_1 shell_command
%type <command> subshell
%type <redirect> redirection redirections
%type <element> simple_command_element

%start inputunit

%left AND SEMI '\n' yacc_EOF
%right PIPE

%%

inputunit:	simple_list '\n' 	/* our SIMPLE_LIST */
			{
			  /* Case of regular command.  Discard the error
			     safety net,and return the command just parsed. */
			  global_command = $1;
			  eof_encountered = 0;
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
			  //handle_eof_input_unit ();
			  YYACCEPT;
			}
	;


redirection:	GREAT WORD
			{
			  redir.filename = $2;
			  $$ = make_redirection (1, r_output_direction, redir);
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
			  REDIRECT *t = $1;

			  while (t->next)
			    t = t->next;
			  t->next = $2; 
			  $$ = $1;
			}
	;

command:	simple_command
			{ $$ = clean_simple_command ($1); }
	|	shell_command
			{ $$ = $1; }
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

shell_command:	shell_command_1
			{ $$ = $1; }
	|	shell_command_1 redirections
			{
			  if ($1->redirects)
			    {
			      REDIRECT *t;
			      for (t = $1->redirects; t->next; t = t->next)
				;
			      t->next = $2;
			    }
			  else
			    $1->redirects = $2;
			  $$ = $1;
			}
	;

shell_command_1:	subshell
			{ $$ = $1; }
	;

subshell:	'(' list ')'
			{ $2->flags |= CMD_WANT_SUBSHELL; $$ = $2; }
	;	

list:		newlines list0
			{ $$ = $2; }
	;

list0:		list1
	|	list1 '\n' newlines
	|	list1 AND newlines
			{ $$ = command_connect ($1, (COMMAND *)NULL, AND); }
	|	list1 SEMI newlines

	;

list1:	//	list1 AND_AND newlines list1
	//		{ $$ = command_connect ($1, $4, AND_AND); }
	//|	list1 OR_OR newlines list1
	//		{ $$ = command_connect ($1, $4, OR_OR); }
		list1 AND newlines list1
			{ $$ = command_connect ($1, $4, AND); }
	|	list1 SEMI newlines list1
			{ $$ = command_connect ($1, $4, SEMI); }
	|	list1 '\n' newlines list1
			{ $$ = command_connect ($1, $4, SEMI); }
	|	pipeline
			{ $$ = $1; }
	;

newlines:
	|	newlines '\n'
	;

/* A simple_list is a list that contains no significant newlines
   and no leading or trailing newlines.  Newlines are allowed
   only following operators, where they are not significant.

   This is what an inputunit consists of.  */

simple_list:	simple_list1
			{ $$ = $1; }
	|	simple_list1 AND
			{ $$ = command_connect ($1, (COMMAND *)NULL, AND); }
	|	simple_list1 SEMI
			{ $$ = $1; }
	;

simple_list1:	//simple_list1 AND_AND newlines simple_list1
		//	{ $$ = command_connect ($1, $4, AND_AND); }
	//|	simple_list1 OR_OR newlines simple_list1
	//		{ $$ = command_connect ($1, $4, OR_OR); }
		simple_list1 AND simple_list1
			{ $$ = command_connect ($1, $3, AND); }
	|	simple_list1 SEMI simple_list1
			{ $$ = command_connect ($1, $3, SEMI); }
	|	pipeline
			{ $$ = $1; }
	;

pipeline:
		pipeline PIPE newlines pipeline
			{ $$ = command_connect ($1, $4, PIPE); }
	|	command
			{ $$ = $1; }
	;

%%

/* Report a syntax error with line numbers, etc.
   Call here for recoverable errors.  If you have a message to print,
   then place it in MESSAGE, otherwise pass NULL and this will figure
   out an appropriate message for you. */
void report_syntax_error (char *message)
{
  if (message)
  {
      if (!interactive)
	  {
	  	char* stream_name = "stdin";
	  	fprintf(stderr, "%s:%d: `%s'", stream_name, line_number, message);
	  }
      else
		fprintf(stderr, "%s", message);

      return;
  }
}

/* Report a syntax error, and restart the parser.  Call here for fatal
   errors. */
void yyerror(char const *s)
{
    report_syntax_error ((char *)NULL);
}

/* The number of times that we have encountered an EOF character without
   another character intervening.  When this gets above the limit, the
   shell terminates. */
int eof_encountered = 0;

/* The limit for eof_encountered. */
int eof_encountered_limit = 10;

/* The globally known line number. */
int line_number = 0;

int main(void)
{
    return yyparse();
}
