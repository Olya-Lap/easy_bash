CPP=g++
CFLAGS=-g -Wall
LEX=flex
YACC=bison
LLIB=-lreadline

my_bash: bash.tab.c lex.yy.c
	$(CPP) $(CFLAGS) bash.tab.c lex.yy.c -o my_bash $(LLIB)
lex.yy.c: bash.l 
	$(LEX) bash.l 
bash.tab.c: bash.y
	$(YACC) -d --report=all bash.y
